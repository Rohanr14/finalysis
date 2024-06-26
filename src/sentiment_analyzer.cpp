#include "sentiment_analyzer.h"
#include "json.hpp"
#include <sstream>

using json = nlohmann::json;
using namespace std;

vector<double> analyzeSentiment(const string& data) {
    auto jsonObj = json::parse(data);

    vector<double> sentimentScores;
    const auto& posts = jsonObj["posts"];
    for (const auto& post : posts) {
        double score = post["sentiment_score"].get<double>();
        sentimentScores.push_back(score);
    }
    return sentimentScores;
}