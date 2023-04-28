#include "string_helpers.hpp"

vector<string> tokenize(string const &str, const char delim) {
    vector<string> out;
    stringstream ss(str);
    string s;

    while (getline(ss, s, delim)) {
        out.push_back(s);
    }

    return out;
}

vector<int> tokenize_to_int(string const &str, const char delim) {
    vector<int> out;
    stringstream ss(str);
    string s;

    while (getline(ss, s, delim)) {
        out.push_back(stoi(s));
    }

    return out;
}

vector<float> tokenize_to_float(string const &str, const char delim) {
    vector<float> out;
    stringstream ss(str);
    string s;

    while (getline(ss, s, delim)) {
        out.push_back(stof(s));
    }

    return out;
}