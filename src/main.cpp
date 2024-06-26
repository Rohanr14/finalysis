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
#include "base64.h"
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

string encode_base64(const string &filename) {
    ifstream file(filename, ios::binary);
    vector<unsigned char> buffer(istreambuf_iterator<char>(file), {});
    return "data:image/png;base64," + base64_encode(reinterpret_cast<const unsigned char*>(buffer.data()), buffer.size());
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

        // Create plot and save to file
        visualizeData(trends);

        // Encode the plot image file as a base64 string
        string base64_plot = encode_base64("plot.png");
        cout << "Base64 plot: " << base64_plot.substr(0, 50) << "..." << endl; // Debugging

        // Create response JSON
        json response;
        response["risk"] = risk;
        response["plot"] = base64_plot;

        res.set_content(response.dump(), "application/json");
    });

    cout << "Server listening on http://localhost:8080" << endl;
    svr.listen("0.0.0.0", 8080);

    return 0;
}