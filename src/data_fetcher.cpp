#include <iostream>
#include "data_fetcher.h"
#include "common_utils.h"
#include <curl/curl.h>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

string fetchData(const string& apiKey, const string& symbol) {
    CURL* curl;
    CURLcode res;
    string readBuffer;

    string url = "https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol=" + symbol + "&interval=1min&apikey=" + apiKey;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        } else {
            cout << "Market Data: " << readBuffer << endl; // Debug output
        }
        curl_easy_cleanup(curl);
    } else {
        cerr << "curl_easy_init() failed" << endl;
    }
    return readBuffer;
}