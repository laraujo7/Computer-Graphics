#ifndef MODEL3D_H
#define MODEL3D_H

#include "../../../../utils/generic_functions.hpp"
#include "../../../lib/glew/glew.h"
#include "../../../utils/file_helpers/file_helpers.hpp"
#include <GL/glut.h>

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Model3D {
private:
  string model_file_path;
  string texture_file_path;

  // default color attributes
  tuple<int, int, int> diffuse = make_tuple(50, 50, 50);
  tuple<int, int, int> ambient = make_tuple(200, 200, 200);
  tuple<int, int, int> specular = make_tuple(0, 0, 0);
  tuple<int, int, int> emissive = make_tuple(0, 0, 0);
  int shininess = 0;

  GLuint vertices, indices;
  unsigned int num_indexs;

  void read_file(string file_path);

public:
  Model3D();

  Model3D(const Model3D &model);

  Model3D(string model_file_path, string texture_file_path,
          tuple<int, int, int> diffuse, tuple<int, int, int> ambient,
          tuple<int, int, int> specular, tuple<int, int, int> emissive,
          int shininess);

  Model3D(string model_file_path);

  string get_model_file_path();

  string get_texture_filepPath();

  tuple<int, int, int> get_diffuse();

  tuple<int, int, int> get_ambient();

  tuple<int, int, int> get_specular();

  tuple<int, int, int> get_emissive();

  tuple<int, int, int> get_cords();

  int get_shininess();

  void set_model_file_path(string path);

  void set_texture_file_path(string path);

  void set_diffuse(tuple<int, int, int> diffuse);

  void set_diffuse(int r, int g, int b);

  void set_ambient(tuple<int, int, int> ambient);

  void set_ambient(int r, int g, int b);

  void set_specular(tuple<int, int, int> specular);

  void set_specular(int r, int g, int b);

  void set_emissive(tuple<int, int, int> emissive);

  void set_emissive(int r, int g, int b);

  void set_shininess(int shininess);

  string model_to_string();

  void draw();
};
#endif