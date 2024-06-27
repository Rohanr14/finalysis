#include "aylien_data.h"
#include "httplib.h"
#include "json.hpp"
#include <vector>
#include <string>
#include <iostream>

using json = nlohmann::json;
using namespace std;
using namespace httplib;

string getBearerToken(const string &username, const string &password) {
    Client cli("https://api.aylien.com");
    Params params;
    params.emplace("grant_type", "password");
    params.emplace("username", username);
    params.emplace("password", password);

    auto res = cli.Post("/v1/oauth/token", params);
    if (res && res->status == 200) {
        auto res_json = json::parse(res->body);
        string token = res_json.value("access_token", "");
        if (token.empty()) {
            throw runtime_error("Bearer token is empty");
        }
        cout << "Bearer token retrieved: " << token << endl;  // Debugging statement
        return token;
    } else {
        throw runtime_error("Failed to retrieve bearer token: " + to_string(res ? res->status : -1));
    }
}

string fetchAylienNewsData(const string &bearerToken, const string &symbol) {
    Client cli("https://api.aylien.com");
    Headers headers = {
        {"Authorization", "Bearer " + bearerToken}
    };

    string query = "/v6/news/stories?aql=text:+(" + symbol + ")+AND+sentiment.title.polarity:(negative+neutral+positive)&cursor=*&published_at.end=NOW&published_at.start=NOW-7DAYS/DAY";
    auto res = cli.Get(query.c_str(), headers);
    if (res && res->status == 200) {
        cout << "News data fetched successfully." << endl;  // Debugging statement
        return res->body;
    } else {
        throw runtime_error("Failed to fetch news data: " + to_string(res ? res->status : -1));
    }
}

vector<double> analyzeAylienSentiment(const string &bearerToken, const string &newsData) {
    vector<double> sentimentScores;

    try {
        Client cli("https://api.aylien.com");
        Headers headers = {
            {"Authorization", "Bearer " + bearerToken},
            {"Content-Type", "application/x-www-form-urlencoded"}
        };

        auto data = json::parse(newsData);
        for (const auto& story : data["stories"]) {
            string text = story["title"].get<string>() + " " + story["body"].get<string>();
            string body = "text=" + text;

            auto res = cli.Post("/v1/sentiment", headers, body, "application/x-www-form-urlencoded");
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
                cerr << "Failed to fetch sentiment data: " << (res ? res->status : -1) << endl;
            }
        }
    } catch (const exception &e) {
        cerr << "Exception occurred: " << e.what() << endl;
    }

    return sentimentScores;
}