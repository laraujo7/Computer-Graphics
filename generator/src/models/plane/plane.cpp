#include "plane.h"
#include <iostream>
void create_plane(float length, int divisions, string file_name) {
  std::vector<Point> points;
  std::vector<tuple<int, int, int>> triangules_indexs;

  for (int i = 0; i <= divisions; i++) {
    for (int j = 0; j <= divisions; j++) {
      float px = (length / 2) - ((j * length) / divisions);
      float pz = (length / 2) - ((i * length) / divisions);

      Point point(px, 0, pz);
      points.push_back(point);
    }
  }

  for (int i = 0; i < divisions * divisions; i += divisions + 1) {
    for (int j = 0; j < divisions; j++) {
      int index1 = j + i;
      int index2 = j + i + divisions + 1;
      int index3 = j + i + divisions + 2;

      triangules_indexs.push_back(make_tuple(index1, index2, index3));

      int index4 = j + i + 1;

      triangules_indexs.push_back(make_tuple(index1, index3, index4));
    }
  }

  Model model(points, triangules_indexs);
  model.writeToFile(file_name, "plane");
}
