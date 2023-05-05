#ifndef UTILS_STRING_HELPERS_H
#define UTILS_STRING_HELPERS_H

#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> tokenize(string const &str, const char delim);

vector<int> tokenize_to_int(string const &str, const char delim);

vector<float> tokenize_to_float(string const &str, const char delim);

int count_char(string &str, char ch);

#endif