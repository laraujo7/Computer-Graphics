#include "spline.hpp"

Spline::Spline(){}

Spline::Spline(vector<Point> points) {
    this->points = points;
    this->index = 0;
}

Point Spline::get_point_by_index(int index) { return (this->points).at(index);}

int Spline::get_index(int t, int point_no){ return ((t + point_no) % (this->points.size()));}

int Spline::get_number_of_points(){ return this->points.size();}

Point Spline::get_spline_point(int time, float elapsed_time) {

    float t = ((elapsed_time/1000) / time);

    //if(t > 1){ (this->index)++;}

    int r = (int)t;

    t = t - r;
    float t_2 = t * t;
    float t_3 = t_2 * t; 

    float q1 = -t_3 + 2.0f * t_2 - t;
    float q2 = 3.0f * t_3 - 5.0f * t_2 + 2.0f;
    float q3 = -3.0f * t_3 + 4.0f * t_2 + t;
    float q4 = t_3 - t_2;


    int i0, i1, i2, i3;
    i0 = get_index(r,0);
    i1 = get_index(r,1);
    i2 = get_index(r,2);
    i3 = get_index(r,3);

    //cout << i0 << "," << i1 << "," << i2 << "," << i3 << "," << endl;

    Point p0 = get_point_by_index(i0);
    Point p1 = get_point_by_index(i1);
    Point p2 = get_point_by_index(i2);
    Point p3 = get_point_by_index(i3);

    float tx = 0.5f * (p0.get_x() * q1 + p1.get_x() * q2 + p2.get_x() * q3 + p3.get_x() * q4);
    float ty = 0.5f * (p0.get_y() * q1 + p1.get_y() * q2 + p2.get_y() * q3 + p3.get_y() * q4);
    float tz = 0.5f * (p0.get_z() * q1 + p1.get_z() * q2 + p2.get_z() * q3 + p3.get_z() * q4);

    return Point(tx,ty,tz);
}