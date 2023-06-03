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

Vector Vector::normalize_vector() {
  float l = sqrt(this->get_x() * this->get_x() + this->get_y() * this->get_y() +
                 this->get_z() * this->get_z());
  this->set_x(this->get_x() / l);
  this->set_y(this->get_y() / l);
  this->set_z(this->get_z() / l);

  return this->vector;
}

static Vector cross(Vector a, Vector b) {
  return Vector(a.get_y() * b.get_z() - a.get_z() * b.get_y(),
               a.get_z() * b.get_x() - a.get_x() * b.get_z(),
               a.get_x() * b.get_y() - a.get_y() * b.get_x());
}

string Vector::vector_to_string() {
  return to_string(this->get_x()) + " " + to_string(this->get_y()) + " " +
         to_string(this->get_z());
}