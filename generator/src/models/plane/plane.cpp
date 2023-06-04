#include "plane.hpp"

void get_plane_points(float length, int divisions, vector<Point> &points) {

  for (int i = 0; i <= divisions; i++) {
    for (int j = 0; j <= divisions; j++) {
      float px = (length / 2) - ((j * length) / divisions);
      float pz = (length / 2) - ((i * length) / divisions);

      points.push_back(Point(px, 0, pz));
    }
  }
}

void get_plane_normals(float length, int divisions, vector<Vector> &normals) {
  for (int i = 0; i <= divisions; i++) {
    for (int j = 0; j <= divisions; j++) {
      normals.push_back(Vector(0, 1, 0));
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
  vector<Point2D> texture_points;
  vector<TriangleIndex> triangules_indexs;
  vector<Vector> normals;

  get_plane_points(length, divisions, points);
  get_plane_indexs(length, divisions, triangules_indexs);
  get_plane_normals(length, divisions, normals);

  Model model(points, triangules_indexs, normals, texture_points);
  model.write_to_file(file_name, "plane");

  return 0;
}
