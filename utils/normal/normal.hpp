#ifndef NORMAL_H
#define NORMAL_H

#include <bits/stdc++.h>

using namespace std;

class Normal {
private:
  tuple<float, float, float> normal;

public:
  Normal();

  Normal(tuple<float, float, float> normal);

  Normal(vector<float> normal);

  Normal(float normal_x, float normal_y, float normal_z);

  float get_x();

  float get_y();

  float get_z();

  void set_x(float x);

  void set_y(float y);

  void set_z(float z);

  Normal normalize_normal();

  Normal cross(Normal a, Normal b);

  string normal_to_string();
};

#endif