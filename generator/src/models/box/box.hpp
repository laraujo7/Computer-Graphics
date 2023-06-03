#ifndef BOX_H
#define BOX_H

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#include "../../../../utils/generic_functions/generic_functions.hpp"
#include "../../../../utils/point/point.hpp"
#include "../../classes/model/model.hpp"
#include "../../classes/triangle_index/triangle_index.hpp"

void get_box_points(float length, int divisions, vector<Point> &points);
void get_box_indexs(float length, int divisions,
                    vector<TriangleIndex> &triangules_indexs);
void get_box_normals(float length, int divisions, vector<Point> &normals);
int create_box(float length, int divisions, string file_name);

using namespace std;

#endif