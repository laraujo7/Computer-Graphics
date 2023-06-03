#include "vector.hpp"

Vector::Vector() {}

Vector::Vector(tuple<float, float, float> vector) { this->vector = vector; }

Vector::Vector(::vector<float> vector) {
  this->vector = make_tuple(vector[0], vector[1], vector[2]);
}

Vector::Vector(float vector_x, float vector_y, float vector_z) {
  this->vector = make_tuple(vector_x, vector_y, vector_z);
}

float Vector::get_x() { return get<0>(this->vector); }

float Vector::get_y() { return get<1>(this->vector); }

float Vector::get_z() { return get<2>(this->vector); }

void Vector::set_x(float x) { get<0>(this->vector) = x; }

void Vector::set_y(float y) { get<1>(this->vector) = y; }

void Vector::set_z(float z) { get<2>(this->vector) = z; }

string Vector::vector_to_string() {
  return to_string(this->get_x()) + " " + to_string(this->get_y()) + " " +
         to_string(this->get_z());
}