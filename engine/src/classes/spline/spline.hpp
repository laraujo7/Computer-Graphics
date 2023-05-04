#ifndef SPLINE_H
#define SPLINE_H

#include "../../../../utils/point/point.hpp"
#include <GL/glut.h>
#include <vector>

using namespace std;

class Spline {
private:
  vector<Point> points;
  int index;

public:
  Spline();

  Spline(vector<Point> points);

  Point get_point_by_index(int index);

  int get_index(int t, int point_no);

  int get_number_of_points();

  Point get_spline_point(int duration, float t);

  float *buildRotMatrix(Point x, Point y, Point z);

  float *get_spline_derivate(int time, float elapsed_time, Point *yAxis);

  Point aligned_translation(int time, float elapsed_time, Point *yAxis,
                            bool align);
};

#endif