#ifndef MODEL_H
#define MODEL_H

#include "../point/point.h"
#include <bits/stdc++.h>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <vector>

using namespace std;

class Model {
private:
  vector<Point> points;
  vector<tuple<int, int, int>> triangules_indexs;

public:
  Model() {}

  Model(vector<Point> points, vector<tuple<int, int, int>> triangules_indexs) {
    this->points = points;
    this->triangules_indexs = triangules_indexs;
  }

  void writeToFile(string filename, char const *tag);
};

#endif