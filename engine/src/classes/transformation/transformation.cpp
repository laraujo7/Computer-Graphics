#include "transformation.hpp"
#include <GL/freeglut_std.h>
#include <GL/gl.h>

Transformation::Transformation() { this->yAxis = Point(0, 1, 0); }

Transformation::Transformation(float x, float y, float z) {
  this->animation = false;
  this->yAxis = Point(0, 1, 0);
  this->x = x;
  this->y = y;
  this->z = z;
}

Transformation::Transformation(float angle, float x, float y, float z) {
  this->animation = false;
  this->yAxis = Point(0, 1, 0);
  this->angle = angle;
  this->x = x;
  this->y = y;
  this->z = z;
}

Transformation::Transformation(int time, float x, float y, float z) {
  this->animation = true;
  this->time = time;
  this->x = x;
  this->y = y;
  this->z = z;
}

Transformation::Transformation(int time, bool align, Spline spline) {
  this->animation = true;
  this->yAxis = Point(0, 1, 0);
  this->time = time;
  this->align = align;
  this->spline = spline;
  this->x = spline.get_point_by_index(1).get_x();
  this->y = spline.get_point_by_index(1).get_y();
  this->z = spline.get_point_by_index(1).get_z();
}

void Transformation::get_translate(int elapsed_time) {
  if (this->animation) {
    Point pos = this->spline.aligned_translation(time, elapsed_time,
                                                 &this->yAxis, this->align);
    this->x = pos.get_x();
    this->y = pos.get_y();
    this->z = pos.get_z();
  } else {
    glTranslatef(this->x, this->y, this->z);
  }
}

void Transformation::get_catmullrom_curve() {
  if (this->animation) {
    int t = 0;
    int no_points = spline.get_number_of_points();

    for (int i = 0; i < (no_points * this->time * 100); ++i, t += 100) {
      Point p1 = this->spline.get_spline_point(time, t);
      Point p2 = this->spline.get_spline_point(time, t + 100);
      glVertex3f(p1.get_x(), p1.get_y(), p1.get_z());
      glVertex3f(p2.get_x(), p2.get_y(), p2.get_z());
    }
  }
}

Point Transformation::get_translate() {
  return make_tuple(this->x, this->y, this->z);
}

tuple<float, float, float> Transformation::get_scale() {
  return make_tuple(this->x, this->y, this->z);
}

void Transformation::get_time_based_rotation() {
  int elapsed_time = glutGet(GLUT_ELAPSED_TIME);
  float seg = 360.0f / this->time;
  float r = elapsed_time / 1000.0f - (int)(elapsed_time / 1000.0f);
  this->angle = (((int)(elapsed_time / 1000.0f) % this->time) + r) * seg;
}

tuple<float, float, float, float> Transformation::get_rotate() {
  if (this->animation)
    get_time_based_rotation();
  return make_tuple(this->angle, this->x, this->y, this->z);
}

int Transformation::get_spline_size() {
  if (!(this->animation))
    return 0;
  return this->spline.get_number_of_points();
}

void Transformation::set_translate(float x, float y, float z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

void Transformation::set_scale(float x, float y, float z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

void Transformation::set_rotate(float angle, float x, float y, float z) {
  this->angle = angle;
  this->x = x;
  this->y = y;
  this->z = z;
}