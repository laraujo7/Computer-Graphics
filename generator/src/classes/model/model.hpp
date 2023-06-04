#ifndef MODEL_H
#define MODEL_H

#include "../../../../utils/normal/normal.hpp"
#include "../../../../utils/point/point.hpp"
#include "../triangle_index/triangle_index.hpp"
#include <bits/stdc++.h>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <vector>

using namespace std;

class Model {
private:
  vector<Point> points;
  vector<TriangleIndex> triangles_indexs;
  vector<Normal> normals;

public:
  Model();

  Model(vector<Point> points, vector<TriangleIndex> triangles_indexs,
        vector<Normal> normals);

  void write_to_file(string filename, char const *tag);
};

#endif