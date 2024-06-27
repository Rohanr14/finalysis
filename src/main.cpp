#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <future>
#include "httplib.h"
#include "json.hpp"
#include "data_fetcher.h"
#include "data_processor.h"
#include "trend_analyzer.h"
#include "risk_assessor.h"
#include "aylien_data.h"

using json = nlohmann::json;
using namespace httplib;
using namespace std;

string read_file(const string &path) {
    ifstream file(path);
    if (!file.is_open()) {
        return "";
    }
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main() {
    Server svr;

    svr.Get("/", [](const Request &req, Response &res) {
        res.set_content(read_file("../web/index.html"), "text/html");
    });

    svr.Get("/script.js", [](const Request &req, Response &res) {
        res.set_content(read_file("../web/script.js"), "application/javascript");
    });

    svr.Get("/style.css", [](const Request &req, Response &res) {
        res.set_content(read_file("../web/style.css"), "text/css");
    });

    svr.Get("/particles.min.js", [](const Request &req, Response &res) {
        res.set_content(read_file("../web/particles.min.js"), "application/javascript");
    });

    svr.Get("/particles.json", [](const Request &req, Response &res) {
        res.set_content(read_file("../web/particles.json"), "application/json");
    });

    svr.Get("/dollar_sign.png", [](const Request &req, Response &res) {
        res.set_content(read_file("../web/dollar_sign.png"), "image/png");
    });

    svr.Post("/analyze", [](const Request &req, Response &res) {
        json j = json::parse(req.body);
        string symbol = j["symbol"];
        bool applySentiment = j["applySentiment"];
        const char* username = getenv("AYLIEN_USERNAME");
        const char* password = getenv("AYLIEN_PASSWORD");

        const char* alphaVantageApiKey = getenv("ALPHA_VANTAGE_API_KEY");
        if (!alphaVantageApiKey) {
            res.status = 500;
            res.set_content("ALPHA_VANTAGE_API_KEY environment variable is not set.", "text/plain");
            return;
        }

        cout << "Analyzing symbol: " << symbol << endl;

        try {
            auto fetchMarketDataFuture = async(launch::async, [&]() {
                return fetchData(alphaVantageApiKey, symbol);
            });

            vector<double> sentimentScores;
            if (applySentiment) {
                cout << "Fetching sentiment data using AYLIEN..." << endl;
                auto fetchSentimentDataFuture = async(launch::async, [&]() {
                    string bearerToken = getBearerToken(username, password);
                    string newsData = fetchAylienNewsData(bearerToken, symbol);
                    return analyzeAylienSentiment(bearerToken, newsData);
                });
                sentimentScores = fetchSentimentDataFuture.get();
            } else {
                cout << "Skipping sentiment analysis..." << endl;
            }

            string marketData = fetchMarketDataFuture.get();
            auto processedMarketData = processData(marketData);
            cout << "Processed market data." << endl;

            auto trends = analyzeTrends(processedMarketData);
            auto risk = assessRisk(processedMarketData, sentimentScores);

            json response;
            response["risk"] = risk;
            response["data"] = processedMarketData;

            res.set_content(response.dump(), "application/json");
        } catch (const exception &e) {
            res.status = 500;
            res.set_content("Error: " + string(e.what()), "text/plain");
        }
    });

    cout << "Server listening on http://localhost:8080" << endl;
    svr.listen("0.0.0.0", 8080);

    return 0;
}