#include "box.h"

void bget_points(float length, int divisions, vector<Point> &points) {

  for (int face = 0; face < 6; face++) {
    for (int i = 0; i <= divisions; i++) {
      for (int j = 0; j <= divisions; j++) {
        float pj = (length / 2) - ((j * length) / divisions);
        float pi = (length / 2) - ((i * length) / divisions);

        Point point;
        switch (face) {
        case 0:
          // Top
          point = Point(pj, length / 2, pi);
          points.push_back(point);
          break;
        case 1:
          // Front
          point = Point(pj, pi, length / 2);
          points.push_back(point);
          break;

        case 2:
          // Left
          point = Point(length / 2, pj, pi);
          points.push_back(point);
          break;

        case 3:
          // Bottom
          point = Point(pj, -length / 2, pi);
          points.push_back(point);
          break;

        case 4:
          // Back
          point = Point(pj, pi, -length / 2);
          points.push_back(point);
          break;

        case 5:
          // Right
          point = Point(-length / 2, pj, pi);
          points.push_back(point);
          break;

        default:
          break;
        }
      }
    }
  }
}

void bget_indexs(float length, int divisions,
                 vector<TriangleIndex> &triangules_indexs) {

  for (int face = 0; face < 6; face++) {
    for (int i = 0; i < divisions * divisions; i += divisions + 1) {
      for (int j = 0; j < divisions; j++) {
        int index1 = j + i;
        int index2 = j + i + divisions + 1;
        int index3 = j + i + divisions + 2;
        int index4 = j + i + 1;

        if (face < 3) {
          triangules_indexs.push_back(TriangleIndex(index1, index2, index3));
          triangules_indexs.push_back(TriangleIndex(index1, index3, index4));
        } else {
          triangules_indexs.push_back(TriangleIndex(index1, index3, index2));
          triangules_indexs.push_back(TriangleIndex(index1, index4, index3));
        }
      }
    }
  }
}

int create_box(float length, int divisions, string file_name) {
  vector<Point> points;
  vector<TriangleIndex> triangules_indexs;

  bget_points(length, divisions, points);

  bget_indexs(length, divisions, triangules_indexs);

  Model model(points, triangules_indexs);
  model.writeToFile(file_name, "box");

  return 0;
}