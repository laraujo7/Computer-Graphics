#include "model.hpp"

string DEFAULT_SAVE_FILE_PATH = "../engine/models/";

Model ::Model() {}

Model ::Model(vector<Point> points, vector<TriangleIndex> triangules_indexs) {
  this->points = points;
  this->triangules_indexs = triangules_indexs;
}

void Model ::write_to_file(string filename, char const *tag) {

  ofstream file;
  file.open(DEFAULT_SAVE_FILE_PATH + filename);
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