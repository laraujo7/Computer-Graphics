#include "normal.hpp"

Normal::Normal() {}

Normal::Normal(tuple<float, float, float> normal) { this->normal = normal; }

Normal::Normal(vector<float> normal) {
  this->normal = make_tuple(normal[0], normal[1], normal[2]);
}

Normal::Normal(float normal_x, float normal_y, float normal_z) {
  this->normal = make_tuple(normal_x, normal_y, normal_z);
}

float Normal::get_x() { return get<0>(this->normal); }

float Normal::get_y() { return get<1>(this->normal); }

float Normal::get_z() { return get<2>(this->normal); }

void Normal::set_x(float x) { get<0>(this->normal) = x; }

void Normal::set_y(float y) { get<1>(this->normal) = y; }

void Normal::set_z(float z) { get<2>(this->normal) = z; }

Normal Normal::normalize_normal() {
  float l = sqrt(this->get_x() * this->get_x() + this->get_y() * this->get_y() +
                 this->get_z() * this->get_z());
  this->set_x(this->get_x() / l);
  this->set_y(this->get_y() / l);
  this->set_z(this->get_z() / l);

  return this->normal;
}

Normal Normal::cross(Normal a, Normal b) {
  return Normal(a.get_y() * b.get_z() - a.get_z() * b.get_y(),
               a.get_z() * b.get_x() - a.get_x() * b.get_z(),
               a.get_x() * b.get_y() - a.get_y() * b.get_x());
}

string Normal::normal_to_string() {
  return to_string(this->get_x()) + " " + to_string(this->get_y()) + " " +
         to_string(this->get_z());
}