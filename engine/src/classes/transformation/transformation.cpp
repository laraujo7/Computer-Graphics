#include "transformation.hpp"

Transformation::Transformation() {}

Transformation::Transformation(float x, float y, float z) {
  this->animation = false;
  this->x = x;
  this->y = y;
  this->z = z;
}

Transformation::Transformation(float angle, float x, float y, float z) {
  this->animation = false;
  this->angle = angle;
  this->x = x;
  this->y = y;
  this->z = z;
}

Transformation::Transformation(int time, bool align, Spline spline) {
  this->animation = true;
  this->time = time;
  this->align = align;
  this->spline = spline;
  this->x = spline.get_point_by_index(1).get_x();
  this->y = spline.get_point_by_index(1).get_y();
  this->z = spline.get_point_by_index(1).get_z();
}

Point Transformation::get_translate(int elapsed_time) {
  if(this->animation) {
    Point point = this->spline.get_spline_point(time, elapsed_time);

    this->x = point.get_x();
    this->y = point.get_y();
    this->z = point.get_z();
  }
  //return (this->spline.get_spline_point(elapsed_time/1000));
  return make_tuple(this->x, this->y, this->z);
}

Point Transformation::get_translate() {
  return make_tuple(this->x, this->y, this->z);
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