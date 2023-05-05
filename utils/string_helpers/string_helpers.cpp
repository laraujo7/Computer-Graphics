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

int count_char(string &str, char ch) {
    int c = 0;
    int length = str.length() - 1;
    for (int i = 0; i < length; i++) {
        if (str[i] == ch)
            c++;
    }
    return c;
}