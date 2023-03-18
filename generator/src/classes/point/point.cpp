#include "point.hpp"

Point::Point() {}

Point::Point(tuple<float, float, float> point) { this->point = point; }

Point::Point(float point_x, float point_y, float point_z) {
  this->point = make_tuple(point_x, point_y, point_z);
}

float Point::get_x() { return get<0>(this->point); }

float Point::get_y() { return get<1>(this->point); }

float Point::get_z() { return get<2>(this->point); }

string Point::point_to_string() {
  return to_string(this->get_x()) + " " + to_string(this->get_y()) + " " +
         to_string(this->get_z());
}