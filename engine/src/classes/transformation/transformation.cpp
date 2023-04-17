#include "transformation.hpp"

Transformation::Transformation() {}

Transformation::Transformation(float x, float y, float z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

Transformation::Transformation(float angle, float x, float y, float z) {
  this->angle = angle;
  this->x = x;
  this->y = y;
  this->z = z;
}

Transformation::Transformation(int time, bool align, Spline spline) {
  this->time = time;
  this->align = align;
  this->spline = spline;
}

Point Transformation::get_translate(int elapsed_time) {
  return (this->spline.get_spline_point(elapsed_time));
}

tuple<float, float, float> Transformation::get_scale() {
  return make_tuple(this->x, this->y, this->z);
}

tuple<float, float, float, float> Transformation::get_rotate() {
  return make_tuple(this->angle, this->x, this->y, this->z);
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