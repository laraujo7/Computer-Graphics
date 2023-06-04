#ifndef MODEL_CONFIG_H
#define MODEL_CONFIG_H

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ModelConfig {
private:
  string texture_file_path;
  string color;

  // default color attributes
  tuple<float, float, float> diffuse = make_tuple(200, 200, 200);
  tuple<float, float, float> ambient = make_tuple(50, 50, 50);
  tuple<float, float, float> specular = make_tuple(0, 0, 0);
  tuple<float, float, float> emissive = make_tuple(0, 0, 0);
  float shininess = 0;

public:
  ModelConfig();

  ModelConfig(string texture_file_path, string color,
              tuple<float, float, float> diffuse,
              tuple<float, float, float> ambient,
              tuple<float, float, float> specular,
              tuple<float, float, float> emissive, float shininess);

  string get_texture_file_path();

  string get_color();

  tuple<float, float, float> get_diffuse();

  tuple<float, float, float> get_ambient();

  tuple<float, float, float> get_specular();

  tuple<float, float, float> get_emissive();

  float get_shininess();

  void set_texture_file_path(string path);

  void set_color(string color);

  void set_diffuse(tuple<float, float, float> diffuse);

  void set_diffuse(float r, float g, float b);

  void set_ambient(tuple<float, float, float> ambient);

  void set_ambient(float r, float g, float b);

  void set_specular(tuple<float, float, float> specular);

  void set_specular(float r, float g, float b);

  void set_emissive(tuple<float, float, float> emissive);

  void set_emissive(float r, float g, float b);

  void set_shininess(float shininess);
};
#endif
