#ifndef AYLIEN_DATA_H
#define AYLIEN_DATA_H

#include <string>
#include <vector>

using namespace std;

string fetchAylienNewsData(const string &apiKey, const string &appId, const string &symbol);
vector<double> analyzeAylienSentiment(const string &apiKey, const string &appId, const string &newsData);

#endif // AYLIEN_DATA_H