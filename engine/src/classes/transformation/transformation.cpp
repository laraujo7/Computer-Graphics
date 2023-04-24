#include "transformation.hpp"

Transformation::Transformation() {
  Point yAxis = Point(0,1,0); 

}

Transformation::Transformation(float x, float y, float z) {
  this->animation = false;
  Point yAxis = Point(0,1,0); 
  this->x = x;
  this->y = y;
  this->z = z;
}

Transformation::Transformation(float angle, float x, float y, float z) {
  this->animation = false;
  Point yAxis = Point(0,1,0); 
  this->angle = angle;
  this->x = x;
  this->y = y;
  this->z = z;
}

Transformation::Transformation(int time, bool align, Spline spline) {
  this->animation = true;
  Point yAxis = Point(0,1,0);
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

void Transformation::alignment(int elapsed_time) {
  if(this->animation)
    this->spline.get_spline_derivate(time, elapsed_time, this->yAxis);

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

int Transformation::get_spline_size() { 
  if(!(this->animation)) return 0;
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