#include "plane.h"

void get_plane_points(float length, int divisions, vector<Point> &points) {

  for (int i = 0; i <= divisions; i++) {
    for (int j = 0; j <= divisions; j++) {
      float px = (length / 2) - ((j * length) / divisions);
      float pz = (length / 2) - ((i * length) / divisions);

      points.push_back(Point(px, 0, pz));
    }
  }
}

void get_plane_indexs(float length, int divisions,
                      vector<TriangleIndex> &triangules_indexs) {

  for (int i = 0; i < divisions * divisions; i += divisions + 1) {
    for (int j = 0; j < divisions; j++) {
      int p1_X = j + i;
      int p1_Y = j + i + divisions + 1;
      int p1_Z = j + i + divisions + 2;
      triangules_indexs.push_back(TriangleIndex(p1_X, p1_Y, p1_Z));

      int p2_Z = j + i + 1;
      triangules_indexs.push_back(TriangleIndex(p1_X, p1_Z, p2_Z));
    }
  }
}

int create_plane(float length, int divisions, string file_name) {
  vector<Point> points;
  vector<TriangleIndex> triangules_indexs;

  get_plane_points(length, divisions, points);
  get_plane_indexs(length, divisions, triangules_indexs);

  Model model(points, triangules_indexs);
  model.writeToFile(file_name, "plane");

  return 0;
}
