#ifndef AYLIEN_DATA_H
#define AYLIEN_DATA_H

#include <string>
#include <vector>

using namespace std;

string getBearerToken(const string &username, const string &password);
string fetchAylienNewsData(const string &bearerToken, const string &symbol);
vector<double> analyzeAylienSentiment(const string &bearerToken, const string &newsData);

#endif //AYLIEN_DATA_H