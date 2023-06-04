#ifndef LIGHT_H
#define LIGHT_H

#include "../../../utils/light_type_helpers/light_type_helpers.hpp"

#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;

class Light {
private:
  LightType light_type;
  int light_index;
  tuple<float, float, float, float> position;
  tuple<float, float, float, float> direction;
  float cutoff;

public:
  Light();

  Light(int light_index, string light_type, float x, float y, float z);

  Light(int light_index, string light_type, float posX, float posY, float posZ,
        float dirX, float dirY, float dirZ, float cutoff);

  void enable_light();

  void setup_light();
  void draw();
};

#endif