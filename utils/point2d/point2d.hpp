#ifndef POINT2D_H
#define POINT2D_H

#include <bits/stdc++.h>

using namespace std;

class Point2D {
private:
  tuple<float, float> point;

public:
  Point2D();

  Point2D(tuple<float, float> point);

  Point2D(vector<float> point);

  Point2D(float point_x, float point_y);

  float get_x();

  float get_y();

  void set_x(float x);

  void set_y(float y);

  string point_to_string();
};

#endif