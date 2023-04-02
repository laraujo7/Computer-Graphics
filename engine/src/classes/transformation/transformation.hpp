#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transformation {
private:
  float x;
  float y;
  float z;
  float angle;

public:
  Transformation();

  Transformation(float x, float y, float z);

  Transformation(float angle, float x, float y, float z);

  tuple<float, float, float> get_translate();

  tuple<float, float, float> get_scale();

  tuple<float, float, float, float> get_rotate();

  void set_translate(float x, float y, float z);

  void set_scale(float x, float y, float z);

  void set_rotate(float angle, float x, float y, float z);
};
#endif
