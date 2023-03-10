#include "sphere.h"

float calcX(float radius, float alpha, float beta) {
  return radius * cos(alpha) * sin(beta);
}

float calcY(float radius, float alpha) { return radius * sin(alpha); }

float calcZ(float radius, float alpha, float beta) {
  return radius * cos(alpha) * cos(beta);
}

void get_sphere_points(float radius, int stacks, int slices,
                       vector<Point> &points) {
  float stackAng = static_cast<float>((M_PI) / stacks);
  float sliceAng = static_cast<float>((2 * M_PI) / slices);

  points.push_back(Point(0, -radius, 0));

  for (int i = 1; i < stacks; i++) {
    float alpha = (i * stackAng) - (M_PI / 2);
    for (int j = 0; j < slices; j++) {
      float beta = j * sliceAng;

      float px = calcX(radius, alpha, beta);
      float py = calcY(radius, alpha);
      float pz = calcZ(radius, alpha, beta);

      points.push_back(Point(px, py, pz));
    }
  }

  points.push_back(Point(0, radius, 0));
}

void get_sphere_indexs(int slices, int stacks, int nPoints,
                       vector<TriangleIndex> &triangules_indexs) {
  for (int i = 1; i <= slices; i++) {
    int y = (i % slices) + 1;
    triangules_indexs.push_back(TriangleIndex(0, y, i));
  }

  for (int i = 1; i < nPoints - slices; i += slices) {
    for (int j = 0; j < slices; j++) {
      int p1_X = i + j;
      int p1_Y = ((j + 1) % slices) + i + slices;
      int p1_Z = p1_X + slices;
      triangules_indexs.push_back(TriangleIndex(p1_X, p1_Y, p1_Z));

      int p2_Y = ((j + 1) % slices) + i;
      triangules_indexs.push_back(TriangleIndex(p1_X, p2_Y, p1_Y));
    }
  }

  for (int i = 1; i <= slices; i++) {
    int x = nPoints;
    int y = x - i;
    int z = x - (i % slices) - 1;
    triangules_indexs.push_back(TriangleIndex(x, y, z));
  }
}

int create_sphere(float radius, int slices, int stacks, string file_name) {
  if (radius < 0 || slices < 1 || stacks < 1)
    return 1;

  vector<Point> points;
  vector<TriangleIndex> triangules_indexs;

  get_sphere_points(radius, stacks, slices, points);
  get_sphere_indexs(slices, stacks, points.size() - 1, triangules_indexs);

  Model model(points, triangules_indexs);
  model.writeToFile(file_name, "sphere");

  return 0;
}