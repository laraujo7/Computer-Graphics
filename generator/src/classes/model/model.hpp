#ifndef MODEL_H
#define MODEL_H

#include "../point/point.hpp"
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
  vector<TriangleIndex> triangules_indexs;

public:
  Model();

  Model(vector<Point> points, vector<TriangleIndex> triangules_indexs);

  void write_to_file(string filename, char const *tag);
};

#endif