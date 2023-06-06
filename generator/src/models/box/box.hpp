#ifndef BOX_H
#define BOX_H

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#include "../../../../utils/generic_functions/generic_functions.hpp"
#include "../../../../utils/normal/normal.hpp"
#include "../../../../utils/point/point.hpp"
#include "../../classes/model/model.hpp"
#include "../../classes/triangle_index/triangle_index.hpp"

void get_box_points_normals(float length, int divisions, vector<Point> &points,
                            vector<Normal> &normals);
void get_box_indexs(float length, int divisions,
                            vector<TriangleIndex> &triangules_indexs);
int create_box(float length, int divisions, string file_name);

using namespace std;

#endif