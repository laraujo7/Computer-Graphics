#include "point.hpp"

Point::Point() {}

Point::Point(tuple<float, float, float> point) { this->point = point; }

Point::Point(vector<float> point) {
  this->point = make_tuple(point[0], point[1], point[2]);
}

Point::Point(float point_x, float point_y, float point_z) {
  this->point = make_tuple(point_x, point_y, point_z);
}

float Point::get_x() { return get<0>(this->point); }

float Point::get_y() { return get<1>(this->point); }

float Point::get_z() { return get<2>(this->point); }

void Point::set_x(float x) { get<0>(this->point) = x; }

void Point::set_y(float y) { get<1>(this->point) = y; }

void Point::set_z(float z) { get<2>(this->point) = z; }

string Point::point_to_string() {
  return to_string(this->get_x()) + " " + to_string(this->get_y()) + " " +
         to_string(this->get_z());
}