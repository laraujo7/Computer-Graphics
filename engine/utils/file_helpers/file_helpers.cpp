#include "file_helpers.hpp"

string get_file_line(ifstream& file) {
  string line;
  getline(file, line);
  return line;
}