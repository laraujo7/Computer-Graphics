#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "../spline/spline.hpp"
#include "../../../../utils/point/point.hpp"
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
  int time;
  bool align;
  Spline spline;
  bool animation;
  Point yAxis;

public:
  Transformation();

  Transformation(float x, float y, float z);

  Transformation(float angle, float x, float y, float z);

  Transformation(int time, bool align, Spline spline);

  int get_spline_size();

  Point get_translate(int elapsed_time);

  void alignment(int elapsed_time);

  Point get_translate();

  tuple<float, float, float> get_scale();

  tuple<float, float, float, float> get_rotate();

  void set_translate(float x, float y, float z);

  void set_scale(float x, float y, float z);

  void set_rotate(float angle, float x, float y, float z);
};
#endif
