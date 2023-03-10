#ifndef POINT_H
#define POINT_H

#include <bits/stdc++.h>

using namespace std;

class Point {
private:
  tuple<float, float, float> point;

public:
  Point() {}

  Point(tuple<float, float, float> point) { this->point = point; }

  Point(float pointX, float pointY, float pointZ) {
    this->point = make_tuple(pointX, pointY, pointZ);
  }

  float getX() { return get<0>(this->point); }

  float getY() { return get<1>(this->point); }

  float getZ() { return get<2>(this->point); }

  string point_to_string() {
    return to_string(this->getX()) + " " + to_string(this->getY()) + " " +
           to_string(this->getZ());
  }
};

#endif