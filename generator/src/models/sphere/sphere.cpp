#include "sphere.h"

float calcX(float radius, float alpha, float beta) {
  return radius * cos(alpha) * sin(beta);
}

float calcY(float radius, float alpha) { return radius * sin(alpha); }

float calcZ(float radius, float alpha, float beta) {
  return radius * cos(alpha) * cos(beta);
}

void get_points(float radius, int stacks, int slices, float stackAng,
                float sliceAng, vector<Point> &points) {

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

void get_indexs(int slices, int stacks, int nPoints,
                vector<TriangleIndex> &triangules_indexs) {
  for (int i = 1; i <= slices; i++) {
    int index2 = (i % slices) + 1;
    triangules_indexs.push_back(TriangleIndex(0, index2, i));
  }

  for (int i = 1; i < nPoints - slices; i += slices) {
    for (int j = 0; j < slices; j++) {
      int index1 = i + j;
      int index2 = ((j + 1) % slices) + i + slices;
      int index3 = index1 + slices;
      triangules_indexs.push_back(TriangleIndex(index1, index2, index3));

      int index4 = index1;
      int index5 = ((j + 1) % slices) + i;
      int index6 = index2;
      triangules_indexs.push_back(TriangleIndex(index4, index5, index6));
    }
  }

  for (int i = 1; i <= slices; i++) {
    int index1 = nPoints;
    int index2 = index1 - i;
    int index3 = index1 - (i % slices) - 1;
    triangules_indexs.push_back(TriangleIndex(index1, index2, index3));
  }
}

int create_sphere(float radius, int slices, int stacks, string file_name) {
  if (radius < 0 || slices < 1 || stacks < 1)
    return 1;

  vector<Point> points;
  vector<TriangleIndex> triangules_indexs;
  float stackAng = static_cast<float>((M_PI) / stacks);
  float sliceAng = static_cast<float>((2 * M_PI) / slices);
  get_points(radius, stacks, slices, stackAng, sliceAng, points);
  get_indexs(slices, stacks, points.size() - 1, triangules_indexs);

  Model model(points, triangules_indexs);
  model.writeToFile(file_name, "sphere");

  return 0;
}