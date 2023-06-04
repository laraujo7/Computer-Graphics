#include "point2d.hpp"

Point2D::Point2D() {}

Point2D::Point2D(tuple<float, float> point) { this->point = point; }

Point2D::Point2D(vector<float> point) {
  this->point = make_tuple(point[0], point[1]);
}

Point2D::Point2D(float point_x, float point_y) {
  this->point = make_tuple(point_x, point_y);
}

float Point2D::get_x() { return get<0>(this->point); }

float Point2D::get_y() { return get<1>(this->point); }

void Point2D::set_x(float x) { get<0>(this->point) = x; }

void Point2D::set_y(float y) { get<1>(this->point) = y; }

string Point2D::point_to_string() {
  return to_string(this->get_x()) + " " + to_string(this->get_y());
}