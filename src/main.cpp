#include <iostream>
#include <cstdlib>
#include "data_fetcher.h"
#include "data_processor.h"
#include "trend_analyzer.h"
#include "sentiment_analyzer.h"
#include "risk_assessor.h"
#include "twitter_data.h"
#include "visualizer.h"

int main() {
    const char* alphaVantageApiKey = getenv("ALPHA_VANTAGE_API_KEY");
    const char* bearerToken = getenv("TWITTER_BEARER_TOKEN");

    // Ensure the environment variables are set
    if (!alphaVantageApiKey || !bearerToken) {
        cerr << "Error: Missing API keys in environment variables." << endl;
        return 1;
    }

    // Fetch and process financial data
    string symbol = "AAPL";
    cout << "Fetching market data..." << endl;
    string marketData = fetchData(alphaVantageApiKey, symbol);
    cout << "Market data fetched: " << marketData << endl;
    auto processedMarketData = processData(marketData);

    // Fetch and process sentiment data
    cout << "Fetching sentiment data..." << endl;
    string sentimentData = fetchTwitterData(bearerToken, symbol);
    cout << "Sentiment data fetched: " << sentimentData << endl;
    auto sentimentScores = analyzeSentiment(sentimentData);

    // Analyze trends and assess risk
    cout << "Analyzing trends..." << endl;
    auto trends = analyzeTrends(processedMarketData);
    cout << "Trends analyzed." << endl;

    cout << "Assessing risk..." << endl;
    auto risk = assessRisk(processedMarketData, sentimentScores);
    cout << "Risk assessed: " << risk << endl;

    // Visualize data
    cout << "Visualizing data..." << endl;
    visualizeData(trends);
    cout << "Visualization complete." << endl;

    return 0;
}
