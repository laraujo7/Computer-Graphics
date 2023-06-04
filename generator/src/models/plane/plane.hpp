#ifndef PLANE_H
#define PLANE_H

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#include "../../../../utils/normal/normal.hpp"
#include "../../../../utils/point/point.hpp"
#include "../../classes/model/model.hpp"
#include "../../classes/triangle_index/triangle_index.hpp"

void get_plane_normals(float length, int divisions, vector<Normal> &normals);
int create_plane(float length, int divisions, string file_name);

using namespace std;

#endif