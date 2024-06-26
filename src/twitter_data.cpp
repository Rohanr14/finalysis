#include "twitter_data.h"
#include "common_utils.h"
#include <curl/curl.h>
#include <iostream>
#include <sstream>
#include "json/json.hpp"
#include "base64.h"

using json = nlohmann::json;
using namespace std;

string fetchTwitterData(const string& bearerToken, const string& query) {
    CURL* curl;
    CURLcode res;
    string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, ("Authorization: Bearer " + bearerToken).c_str());

        string url = "https://api.twitter.com/2/tweets/search/recent?query=" + query;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        } else {
            cout << "Sentiment Data: " << readBuffer << endl; // Debug output
        }
        curl_easy_cleanup(curl);
    } else {
        cerr << "curl_easy_init() failed" << endl;
    }

    return readBuffer;
}