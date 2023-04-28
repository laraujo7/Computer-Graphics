#ifndef UTILS_GENERIC_FUNCTION_H
#define UTILS_GENERIC_FUNCTION_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <type_traits>

using namespace std;

// Why can’t I separate the definition of my templates from its declaration and
// put it inside a .cpp file?
// -> http://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
template <typename T> void print(T string) { cout << string; }

template <typename T, typename... U> void print(T string, U... u) {
  print(string);
  print(u...);
}

template <typename T> void println(T string) {
  cout << string << endl;
}

template <typename T, typename... U> void println(T string, U... u) {
  print(string);
  println(u...);
}

template <typename T> void perror(T string) { cerr << string; }

template <typename T, typename... U> void perror(T string, U... u) {
  perror(string);
  perror(u...);
}

template <typename T> void perrorln(T string) {
  cerr << string << endl;
}

template <typename T, typename... U> void perrorln(T string, U... u) {
  perror(string);
  perrorln(u...);
}

template <typename T>
bool in_array(const T &value, const vector<T> &array) {
  return find(array.begin(), array.end(), value) != array.end();
}

template <typename T>
vector<T> vector_slice(const vector<T>& v, size_t start, size_t end) {
    if (end >= v.size()) {
        end = v.size();
    }

    vector<T> slice(v.begin() + start, v.begin() + end);
    return slice;
}


template <typename T>
vector<vector<T>> multiple_matrices(vector<vector<T>> matrix_one, vector<vector<T>> matrix_two) {
  int number_rows_matrix_one = matrix_one.size();
  int number_rows_matrix_two = matrix_two.size();
  int number_columns_matrix_one = matrix_one[0].size();
  int number_columns_matrix_two = matrix_two[0].size();

  if(number_columns_matrix_one != number_rows_matrix_two) {
        throw invalid_argument("Matrices are not compatible for multiplication.");
    }

  vector<vector<T>> matrix_res(number_rows_matrix_one, vector<T>(number_columns_matrix_two));

  if constexpr (!is_same_v<T, int> && !is_same_v<T, float> && !is_same_v<T, double> && !is_same_v<T, long int> && !is_same_v<T, long double>) {
        throw invalid_argument("Invalid matrix data type.");
  }

  for(int i=0; i < number_rows_matrix_one; i++) {
    for(int j=0; j < number_columns_matrix_two; j++) {
      for(int k=0; k < number_columns_matrix_one; k++) {
        matrix_res[i][j] += matrix_one[i][k] * matrix_two[k][j];
      }
    }
  }

  return matrix_res;
}


template <typename T>
vector<vector<T>> multiple_matrices(vector<T> vector_one, vector<vector<T>> matrix_two) {
  vector<vector<T>> matrix_one(1, vector_one);
  return multiple_matrices(matrix_one, matrix_two);
}

template <typename T>
vector<vector<T>> multiple_matrices(vector<T> vector_one, vector<T> vector_two) {
  vector<vector<T>> matrix_one(1, vector_one);
  vector<vector<T>> matrix_two(1, vector_two);
  return multiple_matrices(matrix_one, matrix_two);
}

#endif