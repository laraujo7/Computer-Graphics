#ifndef SPLINE_H
#define SPLINE_H

#include "../../../../utils/point/point.hpp"
#include <vector>

using namespace std;

class Spline {
private:
    vector<Point> points;
    int index;

public:
    Spline();

    Spline(vector<Point> points);

    Point get_point_by_index(int index);

    int get_index(int t, int point_no);

    int get_number_of_points();

    //Spline(Point p0, Point p1, Point p2, Point p3);

    Point get_spline_point(int duration, float t);
};

#endif