#include "risk_assessor.h"
#include <cmath>
#include <iostream>

using namespace std;

double assessRisk(const vector<double>& marketData, const vector<double>& sentimentScores) {
    if (marketData.empty() || sentimentScores.empty()) {
        cerr << "Error: Empty market data or sentiment scores." << endl;
        return -1.0; // Return an error value
    }

    cout << "Market data size: " << marketData.size() << endl;
    cout << "Sentiment scores size: " << sentimentScores.size() << endl;

    double risk = 0.0;
    size_t dataSize = min(marketData.size(), sentimentScores.size());
    
    for (size_t i = 0; i < dataSize; ++i) {
        double diff = marketData[i] - sentimentScores[i];
        risk += abs(diff);
        cout << "Data[" << i << "]: Market = " << marketData[i] << ", Sentiment = " << sentimentScores[i] << ", Diff = " << diff << endl;
    }

    return risk / dataSize;
}