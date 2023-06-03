#ifndef VECTOR_H
#define VECTOR_H

#include <bits/stdc++.h>

using namespace std;

class Vector {
private:
  tuple<float, float, float> vector;

public:
  Vector();

  Vector(tuple<float, float, float> vector);

  Vector(::vector<float> vector);

  Vector(float vector_x, float vector_y, float vector_z);

  float get_x();

  float get_y();

  float get_z();

  void set_x(float x);

  void set_y(float y);

  void set_z(float z);

  Vector normalize_vector();

  static Vector cross(Vector a, Vector b);

  string vector_to_string();
};

#endif