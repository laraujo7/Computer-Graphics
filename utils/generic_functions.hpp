#ifndef UTILS_GENERIC_FUNCTION_H
#define UTILS_GENERIC_FUNCTION_H

#include <algorithm>
#include <iostream>
#include <vector>

// Why can’t I separate the definition of my templates from its declaration and
// put it inside a .cpp file?
// -> http://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
template <typename T> void print(T string) { std::cout << string; }

template <typename T, typename... U> void print(T string, U... u) {
  print(string);
  print(u...);
}

template <typename T> void println(T string) {
  std::cout << string << std::endl;
}

template <typename T, typename... U> void println(T string, U... u) {
  print(string);
  println(u...);
}

template <typename T> void perror(T string) { std::cerr << string; }

template <typename T, typename... U> void perror(T string, U... u) {
  perror(string);
  perror(u...);
}

template <typename T> void perrorln(T string) {
  std::cerr << string << std::endl;
}

template <typename T, typename... U> void perrorln(T string, U... u) {
  perror(string);
  perrorln(u...);
}

template <typename T>
bool in_array(const T &value, const std::vector<T> &array) {
  return std::find(array.begin(), array.end(), value) != array.end();
}

#endif