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

tuple<float, float, float> Transformation::get_translate() {
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