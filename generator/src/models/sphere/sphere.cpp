#include "sphere.hpp"

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

void get_sphere_normals(float radius, int stacks, int slices,
                       vector<Vector> &normals) {
  float stackAng = static_cast<float>((M_PI) / stacks);
  float sliceAng = static_cast<float>((2 * M_PI) / slices);

  normals.push_back(Vector(0, -radius, 0).normalize_vector());

  for (int i = 1; i < stacks; i++) {
    float alpha = (i * stackAng) - (M_PI / 2);
    for (int j = 0; j < slices; j++) {
      float beta = j * sliceAng;

      float px = calcX(radius, alpha, beta);
      float py = calcY(radius, alpha);
      float pz = calcZ(radius, alpha, beta);

      normals.push_back(Vector(px, py, pz).normalize_vector());
    }
  }

  normals.push_back(Vector(0, radius, 0).normalize_vector());
}

void get_sphere_indexs(int slices, int stacks, int nPoints,
                       vector<TriangleIndex> &triangules_indexs) {
  for (int i = 1; i <= slices; i++) {
    int index2 = (i % slices) + 1;
    triangules_indexs.push_back(TriangleIndex(0, index2, i));
  }

  for (int i = 1; i < nPoints - slices; i += slices) {
    for (int j = 0; j < slices; j++) {
      int t1_i1 = i + j;
      int t1_i2 = ((j + 1) % slices) + i + slices;
      int t1_i3 = t1_i1 + slices;
      triangules_indexs.push_back(TriangleIndex(t1_i1, t1_i2, t1_i3));

      int t2_i2 = ((j + 1) % slices) + i;
      triangules_indexs.push_back(TriangleIndex(t1_i1, t2_i2, t1_i2));
    }
  }

  for (int i = 1; i <= slices; i++) {
    int index1 = nPoints;
    int index2 = index1 - (i % slices) - 1;
    int index3 = index1 - i;
    triangules_indexs.push_back(TriangleIndex(index1, index2, index3));
  }
}

int create_sphere(float radius, int slices, int stacks, string file_name) {
  if (radius < 0 || slices < 1 || stacks < 1)
    return 1;

  vector<Point> points;
  vector<TriangleIndex> triangules_indexs;
  vector<Vector> normals;

  get_sphere_points(radius, stacks, slices, points);
  get_sphere_indexs(slices, stacks, points.size() - 1, triangules_indexs);
  get_sphere_normals(radius, stacks, slices, normals);

  Model model(points, triangules_indexs, normals);
  model.write_to_file(file_name, "sphere");

  return 0;
}