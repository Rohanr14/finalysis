#include "aylien_data.h"
#include "json.hpp"
#include "httplib.h"
#include <vector>
#include <string>
#include <iostream>

using json = nlohmann::json;
using namespace std;
using namespace httplib;

string fetchAylienNewsData(const string &apiKey, const string &appId, const string &symbol) {
    string newsData;

    Client cli("https://api.aylien.com");
    Headers headers = {
        {"X-AYLIEN-NewsAPI-Application-Key", apiKey},
        {"X-AYLIEN-NewsAPI-Application-ID", appId}
    };

    string query = "/stories?title=" + symbol + "&sort_by=published_at&language=en&published_at.start=NOW-7DAYS&published_at.end=NOW";

    auto res = cli.Get(query.c_str(), headers);
    if (res && res->status == 200) {
        newsData = res->body;
    } else {
        cerr << "Failed to fetch news data: " << res.error() << endl;
    }

    cout << "News data fetched: " << newsData.substr(0, 100) << "..." << endl; // Print part of the news data for debugging

    return newsData;
}

vector<double> analyzeAylienSentiment(const string &apiKey, const string &appId, const string &newsData) {
    vector<double> sentimentScores;
    Client cli("https://api.aylien.com");
    Headers headers = {
        {"X-AYLIEN-TextAPI-Application-Key", apiKey},
        {"X-AYLIEN-TextAPI-Application-ID", appId},
        {"Content-Type", "application/x-www-form-urlencoded"}
    };

    auto data = json::parse(newsData);
    for (const auto& story : data["stories"]) {
        string text = story["title"].get<string>() + " " + story["body"].get<string>();
        string body = "text=" + text;

        auto res = cli.Post("/api/v1/sentiment", headers, body, "application/x-www-form-urlencoded");
        if (res && res->status == 200) {
            auto sentimentJson = json::parse(res->body);
            string polarity = sentimentJson["polarity"].get<string>();

            double sentimentScore = 0.0;
            if (polarity == "positive") {
                sentimentScore = 1.0;
            } else if (polarity == "negative") {
                sentimentScore = -1.0;
            }

            sentimentScores.push_back(sentimentScore);
        } else {
            cerr << "Failed to fetch sentiment data: " << res.error() << endl;
        }
    }

    cout << "Sentiment scores: ";
    for (const auto& score : sentimentScores) {
        cout << score << " ";
    }
    cout << endl;

    return sentimentScores;
}