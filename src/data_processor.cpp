#include "data_processor.h"

using json = nlohmann::json;
using namespace std;

vector<double> processData(const string& data) {
    json jsonObj = json::parse(data);

    vector<double> prices;
    const auto& timeSeries = jsonObj["Time Series (1min)"];
    for (const auto& key : timeSeries.items()) {
        prices.push_back(stod(key.value()["1. open"].get<string>()));
    }
    return prices;
}