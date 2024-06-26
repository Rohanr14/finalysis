#ifndef BASE64_H
#define BASE64_H

#include <string>

using namespace std;

string base64_encode(const unsigned char* input, size_t length);

#endif // BASE64_H