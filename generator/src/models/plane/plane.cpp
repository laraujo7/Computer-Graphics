#include "plane.h"

void get_points(float length, int divisions, vector<Point> &points) {

  for (int i = 0; i <= divisions; i++) {
    for (int j = 0; j <= divisions; j++) {
      float px = (length / 2) - ((j * length) / divisions);
      float pz = (length / 2) - ((i * length) / divisions);

      points.push_back(Point(px, 0, pz));
    }
  }
}

void get_indexs(float length, int divisions,
                vector<TriangleIndex> &triangules_indexs) {

  for (int i = 0; i < divisions * divisions; i += divisions + 1) {
    for (int j = 0; j < divisions; j++) {
      int index1 = j + i;
      int index2 = j + i + divisions + 1;
      int index3 = j + i + divisions + 2;

      triangules_indexs.push_back(TriangleIndex(index1, index2, index3));

      int index4 = j + i + 1;

      triangules_indexs.push_back(TriangleIndex(index1, index3, index4));
    }
  }
}

int create_plane(float length, int divisions, string file_name) {
  vector<Point> points;
  vector<TriangleIndex> triangules_indexs;

  get_points(length, divisions, points);
  get_indexs(length, divisions, triangules_indexs);

  Model model(points, triangules_indexs);
  model.writeToFile(file_name, "plane");

  return 0;
}
