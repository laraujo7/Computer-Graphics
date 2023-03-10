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
  for (TriangleIndex triangule_indexs : this->triangules_indexs) {
    file << triangule_indexs.triangle_indexs_to_string() + "\n";
  }

  file.close();
}