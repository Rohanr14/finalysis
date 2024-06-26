#include "common_utils.h"
#include <string>
#include <cstring>

using namespace std;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    string* str = static_cast<string*>(userp);
    str->append(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
}