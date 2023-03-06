#include "model.h"

void Model ::writeToFile(string filename, char const *tag) {

  ofstream file;
  file.open(filename);
  file << tag << "\n";

  file << to_string(this->points.size()) + "\n";

  for (Point point : this->points) {
    file << point.point_to_string() + "\n";
  }

  file << to_string(this->triangules_indexs.size()) + "\n";
  for (tuple<int, int, int> triangule_indexs : this->triangules_indexs) {
    file << get<0>(triangule_indexs) << " " << get<1>(triangule_indexs) << " "
         << get<2>(triangule_indexs) << "\n";
  }

  file.close();
}