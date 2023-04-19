#include "spline.hpp"

Spline::Spline(){}

Spline::Spline(vector<Point> points) {
    this->points = points;
}

Point Spline::get_point_by_index(int index) { return (this->points).at(index);}


Point Spline::get_spline_point(int time, float elapsed_time) {

    #TODO: implementar for loop para aplicar múltiplos pontos (e respetivos pontos de controlo)

    float t = ((elapsed_time/1000) / time);

    float t_2 = t * t;
    float t_3 = t_2 * t; 

    float q1 = -t_3 + 2.0f * t_2 - t;
    float q2 = 3.0f * t_3 - 5.0f * t_2 + 2.0f;
    float q3 = -3.0f * t_3 + 4.0f * t_2 + t;
    float q4 = t_3 - t_2;

    Point p0 = (this->points).at(0);
    Point p1 = (this->points).at(1);
    Point p2 = (this->points).at(2);
    Point p3 = (this->points).at(3);

    float tx = 0.5f * (p0.get_x() * q1 + p1.get_x() * q2 + p2.get_x() * q3 + p3.get_x() * q4);
    float ty = 0.5f * (p0.get_y() * q1 + p1.get_y() * q2 + p2.get_y() * q3 + p3.get_y() * q4);
    float tz = 0.5f * (p0.get_z() * q1 + p1.get_z() * q2 + p2.get_z() * q3 + p3.get_z() * q4);

    return Point(tx,ty,tz);
}