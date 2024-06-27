#include "sentiment_analyzer.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

vector<double> analyzeSentiment(const string &sentimentData) {
    vector<double> sentimentScores;

    // Parse the JSON sentiment data
    auto data = json::parse(sentimentData);
    for (const auto& status : data["statuses"]) {
        string text = status["text"];
        double sentimentScore = 0.0;

        // Simple sentiment analysis (mock)
        if (text.find("Great") != string::npos || text.find("good") != string::npos) {
            sentimentScore = 1.0;
        } else if (text.find("Terrible") != string::npos || text.find("bad") != string::npos) {
            sentimentScore = -1.0;
        }

        sentimentScores.push_back(sentimentScore);
    }

    return sentimentScores;
}