#include "box.hpp"
int nFace = static_cast<int>(6);

void get_box_points_normals(float length, int divisions, vector<Point> &points,
                            vector<Normal> &normals) {

  float half_length = static_cast<float>(length / 2);
  float length_step = static_cast<float>(length / divisions);

  for (int face = 0; face < nFace; face++) {
    for (int i = 0; i <= divisions; i++) {
      for (int j = 0; j <= divisions; j++) {
        float pj = (half_length) - (j * length_step);
        float pi = (half_length) - (i * length_step);

        Point point;
        switch (face) {
        case 0:
          // Bottom
          points.push_back(Point(pj, -half_length, pi));
          normals.push_back(Normal(0, -1, 0));
          break;

        case 1:
          // Front
          points.push_back(Point(pj, pi, half_length));
          normals.push_back(Normal(0, 0, 1));
          break;

        case 2:
          // Left
          points.push_back(Point(half_length, pj, pi));
          normals.push_back(Normal(1, 0, 0));
          break;

        case 3:
          // Top
          points.push_back(Point(pj, half_length, pi));
          normals.push_back(Normal(0, 1, 0));
          break;

        case 4:
          // Back
          points.push_back(Point(pj, pi, -half_length));
          normals.push_back(Normal(0, 0, -1));
          break;

        case 5:
          // Right
          points.push_back(Point(-half_length, pj, pi));
          normals.push_back(Normal(-1, 0, 0));
          break;

        default:
          break;
        }
      }
    }
  }
}

void get_box_indexs(float length, int divisions,
                            vector<TriangleIndex> &triangules_indexs) {

  int face_points = pow(divisions + 1, 2);

  for (int face = 0; face < nFace; face++) {
    for (int i = 0; i < divisions * divisions; i += divisions + 1) {
      for (int j = 0; j < divisions; j++) {
        int index1 = j + i + (face * face_points);
        int index2 = j + i + divisions + 1 + (face * face_points);
        int index3 = j + i + divisions + 2 + (face * face_points);
        int index4 = j + i + 1 + (face * face_points);

        if (face < 3) {
          triangules_indexs.push_back(TriangleIndex(index1, index3, index2));
          triangules_indexs.push_back(TriangleIndex(index1, index4, index3));
        } else {
          triangules_indexs.push_back(TriangleIndex(index1, index2, index3));
          triangules_indexs.push_back(TriangleIndex(index1, index3, index4));
        }
      }
    }
  }
}

int create_box(float length, int divisions, string file_name) {
  vector<Point> points;
  vector<TriangleIndex> triangles_indexs;
  vector<Normal> normals;

  get_box_points_normals(length, divisions, points, normals);

  get_box_indexs(length, divisions, triangles_indexs);

  Model model(points, triangles_indexs, normals);
  model.write_to_file(file_name, "box");

  return 0;
}