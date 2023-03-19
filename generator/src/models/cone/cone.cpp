#include "cone.hpp"

void get_cone_points(float radius, float height, int slices, int stacks,
                     vector<Point> &points) {
  float heightRatio = static_cast<float>(height / stacks);
  float sliceAng = static_cast<float>((2 * M_PI) / slices);

  points.push_back(Point(0, height, 0));

  for (int i = 1; i <= stacks; i++) {
    float stack_height = height - (i * heightRatio);
    float stack_radius = i * (radius / stacks);
    for (int j = 0; j < slices; j++) {
      float alpha = j * sliceAng;

      float px = stack_radius * sin(alpha);
      float py = stack_height;
      float pz = stack_radius * cos(alpha);

      points.push_back(Point(px, py, pz));
    }
  }

  points.push_back(Point(0, 0, 0));
}

void get_cone_indexs(int slices, int stacks, int nPoints,
                     vector<TriangleIndex> &triangules_indexs) {
  for (int i = 1; i <= slices; i++) {
    int index3 = (i % slices) + 1;

    triangules_indexs.push_back(TriangleIndex(0, i, index3));
  }

  for (int i = 1; i < nPoints - slices; i += slices) {
    for (int j = 0; j < slices; j++) {
      int t1_i1 = i + j;
      int t1_i2 = t1_i1 + slices;
      int t1_i3 = ((j + 1) % slices) + slices + i;
      triangules_indexs.push_back(TriangleIndex(t1_i1, t1_i2, t1_i3));

      int t2_i3 = ((j + 1) % slices) + i;
      triangules_indexs.push_back(TriangleIndex(t1_i1, t1_i3, t2_i3));
    }
  }

  for (int i = 1; i <= slices; i++) {
    int index2 = nPoints - i;
    int index3 = nPoints - (i % slices) - 1;

    triangules_indexs.push_back(TriangleIndex(nPoints, index2, index3));
  }
}

int create_cone(float radius, float height, int slices, int stacks,
                string file_name) {
  if (radius < 0 || height < 0 || slices < 1 || stacks < 1)
    return 1;

  vector<Point> points;
  vector<TriangleIndex> triangules_indexs;

  get_cone_points(radius, height, slices, stacks, points);
  get_cone_indexs(slices, stacks, points.size() - 1, triangules_indexs);

  Model model(points, triangules_indexs);
  model.write_to_file(file_name, "cone");

  return 0;
}