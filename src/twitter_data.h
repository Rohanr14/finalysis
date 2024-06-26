#ifndef TWITTER_DATA_H
#define TWITTER_DATA_H

#include <string>

using namespace std;

string getBearerToken(const string& apiKey, const string& apiSecretKey);
string fetchTwitterData(const string& bearerToken, const string& query);

#endif // TWITTER_DATA_H