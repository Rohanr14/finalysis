#include <iostream>
#include <fstream>
#include <string>
#include "data_fetcher.h"
#include "data_processor.h"
#include "trend_analyzer.h"
#include "sentiment_analyzer.h"
#include "risk_assessor.h"
#include "visualizer.h"
#include "twitter_data.h"
#include "httplib.h"
#include "json.hpp"
#include <vector>
#include <iterator>

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
        const char* alphaVantageApiKey = getenv("ALPHA_VANTAGE_API_KEY");

        cout << "Analyzing symbol: " << symbol << endl;

        // Fetch and process financial data
        string marketData = fetchData(alphaVantageApiKey, symbol);
        auto processedMarketData = processData(marketData);

        vector<double> sentimentScores;

        // If applySentiment is true, fetch and process sentiment data
        if (applySentiment) {
            cout << "Fetching sentiment data..." << endl;
            const char* bearerToken = getenv("TWITTER_BEARER_TOKEN");
            string sentimentData = fetchTwitterData(bearerToken, symbol);
            sentimentScores = analyzeSentiment(sentimentData);
        } else {
            cout << "Skipping sentiment analysis..." << endl;
        }

        // Analyze trends and assess risk
        auto trends = analyzeTrends(processedMarketData);
        auto risk = assessRisk(processedMarketData, sentimentScores);

        // Create response JSON
        json response;
        response["risk"] = risk;
        response["data"] = processedMarketData;

        res.set_content(response.dump(), "application/json");
    });

    cout << "Server listening on http://localhost:8080" << endl;
    svr.listen("0.0.0.0", 8080);

    return 0;
}