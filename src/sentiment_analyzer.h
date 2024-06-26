#ifndef SENTIMENT_ANALYZER_H
#define SENTIMENT_ANALYZER_H

#include <string>
#include <vector>
#include "json.hpp"

using namespace std;

vector<double> analyzeSentiment(const string& data);

#endif // SENTIMENT_ANALYZER_H