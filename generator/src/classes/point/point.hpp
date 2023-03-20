#ifndef POINT_H
#define POINT_H

#include <bits/stdc++.h>

using namespace std;

class Point {
private:
  tuple<float, float, float> point;

public:
  Point();

  Point(tuple<float, float, float> point);

  Point(float point_x, float point_y, float point_z);

  float get_x();

  float get_y();

  float get_z();

  string point_to_string();
};

#endif