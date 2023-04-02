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
  tuple<int, int, int> diffuse = make_tuple(200, 200, 200);
  tuple<int, int, int> ambient = make_tuple(50, 50, 50);
  tuple<int, int, int> specular = make_tuple(0, 0, 0);
  tuple<int, int, int> emissive = make_tuple(0, 0, 0);
  int shininess = 0;

public:
  ModelConfig();

  ModelConfig(string texture_file_path, string color,
              tuple<int, int, int> diffuse, tuple<int, int, int> ambient,
              tuple<int, int, int> specular, tuple<int, int, int> emissive,
              int shininess);

  string get_texture_file_path();

  string get_color();

  tuple<int, int, int> get_diffuse();

  tuple<int, int, int> get_ambient();

  tuple<int, int, int> get_specular();

  tuple<int, int, int> get_emissive();

  int get_shininess();

  void set_texture_file_path(string path);

  void set_color(string color);

  void set_diffuse(tuple<int, int, int> diffuse);

  void set_diffuse(int r, int g, int b);

  void set_ambient(tuple<int, int, int> ambient);

  void set_ambient(int r, int g, int b);

  void set_specular(tuple<int, int, int> specular);

  void set_specular(int r, int g, int b);

  void set_emissive(tuple<int, int, int> emissive);

  void set_emissive(int r, int g, int b);

  void set_shininess(int shininess);
};
#endif
