#include "spline.hpp"
#include <GL/gl.h>
#include <iterator>

Spline::Spline() {}

Spline::Spline(vector<Point> points) {
  this->points = points;
  this->index = 0;
}

Point Spline::get_point_by_index(int index) { return (this->points)[index]; }

int Spline::get_index(int segment_no, int point_no) {
  return ((segment_no + point_no) % (this->points.size()));
}

int Spline::get_number_of_points() { return this->points.size(); }

Point Spline::get_spline_point(int time, float elapsed_time) {

  float animation_state =
      ((elapsed_time / 1000) / time) * this->get_number_of_points();

  int current_segment = (int)animation_state;

  float t = animation_state - current_segment;
  float t_2 = t * t;
  float t_3 = t_2 * t;

  float q1 = -t_3 + 2.0f * t_2 - t;
  float q2 = 3.0f * t_3 - 5.0f * t_2 + 2.0f;
  float q3 = -3.0f * t_3 + 4.0f * t_2 + t;
  float q4 = t_3 - t_2;

  Point p0 = get_point_by_index(get_index(current_segment, 0));
  Point p1 = get_point_by_index(get_index(current_segment, 1));
  Point p2 = get_point_by_index(get_index(current_segment, 2));
  Point p3 = get_point_by_index(get_index(current_segment, 3));

  float tx = 0.5f * (p0.get_x() * q1 + p1.get_x() * q2 + p2.get_x() * q3 +
                     p3.get_x() * q4);
  float ty = 0.5f * (p0.get_y() * q1 + p1.get_y() * q2 + p2.get_y() * q3 +
                     p3.get_y() * q4);
  float tz = 0.5f * (p0.get_z() * q1 + p1.get_z() * q2 + p2.get_z() * q3 +
                     p3.get_z() * q4);

  return Point(tx, ty, tz);
}

void normalize(Point *a) {

  float l = sqrt(a->get_x() * a->get_x() + a->get_y() * a->get_y() +
                 a->get_z() * a->get_z());
  a->set_x(a->get_x() / l);
  a->set_y(a->get_y() / l);
  a->set_z(a->get_z() / l);
}

float *Spline::buildRotMatrix(Point x, Point y, Point z) {
  static float m[16] = {
      x.get_x(), x.get_y(), x.get_z(), 0, y.get_x(), y.get_y(), y.get_z(), 0,
      z.get_x(), z.get_y(), z.get_z(), 0, 0,         0,         0,         1};
  return m;
}

Point cross(Point a, Point b) {
  return Point(a.get_y() * b.get_z() - a.get_z() * b.get_y(),
               a.get_z() * b.get_x() - a.get_x() * b.get_z(),
               a.get_x() * b.get_y() - a.get_y() * b.get_x());
}

float *Spline::get_spline_derivate(int time, float elapsed_time, Point *yAxis) {

  float animation_state =
      ((elapsed_time / 1000) / time) * this->get_number_of_points();

  int current_segment = (int)animation_state;

  float t = animation_state - current_segment;
  float t_2 = t * t;
  float t_3 = t_2 * t;

  Point p0 = get_point_by_index(get_index(current_segment, 0));
  Point p1 = get_point_by_index(get_index(current_segment, 1));
  Point p2 = get_point_by_index(get_index(current_segment, 2));
  Point p3 = get_point_by_index(get_index(current_segment, 3));

  // X = P'(t)
  float q1 = -3.0f * t_2 + 4.0f * t - 1.0f;
  float q2 = 9.0f * t_2 - 10.0f * t;
  float q3 = -9.0f * t_2 + 8.0f * t + 1.0f;
  float q4 = 3.0f * t_2 - 2.0f * t;

  float tx = 0.5f * (p0.get_x() * q1 + p1.get_x() * q2 + p2.get_x() * q3 +
                     p3.get_x() * q4);
  float ty = 0.5f * (p0.get_y() * q1 + p1.get_y() * q2 + p2.get_y() * q3 +
                     p3.get_y() * q4);
  float tz = 0.5f * (p0.get_z() * q1 + p1.get_z() * q2 + p2.get_z() * q3 +
                     p3.get_z() * q4);

  Point x = Point(tx, ty, tz);

  Point z = cross(x, *yAxis);

  // Y
  *yAxis = cross(z, x);

  normalize(&x);
  normalize(&z);
  normalize(yAxis);

  return buildRotMatrix(x, *yAxis, z);
}

Point Spline::aligned_translation(int time, float elapsed_time, Point *yAxis,
                                  bool align) {
  float *matrix = get_spline_derivate(time, elapsed_time, yAxis);
  Point translate = get_spline_point(time, elapsed_time);

  glTranslatef(translate.get_x(), translate.get_y(), translate.get_z());
  if (align)
    glMultMatrixf(matrix);

  return translate;
}