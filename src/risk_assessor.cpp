#include "risk_assessor.h"
#include <cmath>
#include <iostream>

using namespace std;

double assessRisk(const vector<double>& marketData, const vector<double>& sentimentScores) {
    if (marketData.empty()) {
        cerr << "Error: Empty market data." << endl;
        return -1.0; // Return an error value
    }

    if (sentimentScores.empty()) {
        cout << "No sentiment scores provided, calculating risk based on market data only." << endl;
        // Calculate risk based on market data only
        double risk = 0.0;
        for (const auto& price : marketData) {
            risk += abs(price); // Example calculation, adjust as needed
        }
        return risk / marketData.size();
    }

    double risk = 0.0;
    size_t dataSize = min(marketData.size(), sentimentScores.size());

    for (size_t i = 0; i < dataSize; ++i) {
        double diff = marketData[i] - sentimentScores[i];
        risk += abs(diff);
    }

    return risk / dataSize;
}