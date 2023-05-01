#include "spline.hpp"
#include <GL/gl.h>
#include <iterator>

Spline::Spline() {}

Spline::Spline(vector<Point> points) {
  this->points = points;
  this->index = 0;
}

Point Spline::get_point_by_index(int index) { return (this->points).at(index); }

int Spline::get_index(int t, int point_no) {
  return ((t + point_no) % (this->points.size()));
}

int Spline::get_number_of_points() { return this->points.size(); }

Point Spline::get_spline_point(int time, float elapsed_time) {

  float t = ((elapsed_time / 1000) / time);

  int r = (int)t;

  t = t - r;
  float t_2 = t * t;
  float t_3 = t_2 * t;

  float q1 = -t_3 + 2.0f * t_2 - t;
  float q2 = 3.0f * t_3 - 5.0f * t_2 + 2.0f;
  float q3 = -3.0f * t_3 + 4.0f * t_2 + t;
  float q4 = t_3 - t_2;

  Point p0 = get_point_by_index(get_index(r, 0));
  Point p1 = get_point_by_index(get_index(r, 1));
  Point p2 = get_point_by_index(get_index(r, 2));
  Point p3 = get_point_by_index(get_index(r, 3));

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

void Spline::buildRotMatrix(Point x, Point y, Point z, float *m) {

  m[0] = x.get_x();
  m[1] = x.get_y();
  m[2] = x.get_z();
  m[3] = 0;
  m[4] = y.get_x();
  m[5] = y.get_y();
  m[6] = y.get_z();
  m[7] = 0;
  m[8] = z.get_x();
  m[9] = z.get_y();
  m[10] = z.get_z();
  m[11] = 0;
  m[12] = 0;
  m[13] = 0;
  m[14] = 0;
  m[15] = 1;
}

Point cross(Point a, Point b) {
  Point res;

  res.set_x((a.get_y() * b.get_z() - a.get_z() * b.get_y()));
  res.set_y((a.get_z() * b.get_x() - a.get_x() * b.get_z()));
  res.set_z((a.get_x() * b.get_y() - a.get_y() * b.get_x()));

  return res;
}

void Spline::get_spline_derivate(int time, float elapsed_time, Point *yAxis,
                                 float *m) {

  float t = ((elapsed_time / 1000) / time);

  int r = (int)t;

  t = t - r;
  float t_2 = t * t;
  float t_3 = t_2 * t;

  Point p0 = get_point_by_index(get_index(r, 0));
  Point p1 = get_point_by_index(get_index(r, 1));
  Point p2 = get_point_by_index(get_index(r, 2));
  Point p3 = get_point_by_index(get_index(r, 3));

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

  buildRotMatrix(x, *yAxis, z, m);
}

Point Spline::aligned_translation(int time, float elapsed_time, Point *yAxis,
                                  bool align) {
  float m[16];
  get_spline_derivate(time, elapsed_time, yAxis, m);
  Point translate = get_spline_point(time, elapsed_time);

  glTranslatef(translate.get_x(), translate.get_y(), translate.get_z());
  if (align)
    glMultMatrixf(m);

  return translate;
}