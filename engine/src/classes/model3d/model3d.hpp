#ifndef MODEL3D_H
#define MODEL3D_H

#include "../../../../utils/generic_functions.hpp"
#include "../../../lib/glew/glew.h"
#include "../../../utils/colors_helpers/colors_helpers.hpp"
#include "../../../utils/file_helpers/file_helpers.hpp"
#include "../modelConfig/modelConfig.hpp"

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

  GLuint vertices, indices;
  unsigned int num_indexs;

  void read_file(string file_path);

public:
  Model3D();

  Model3D(const Model3D &model);

  Model3D(string model_file_path);

  string get_model_file_path();

  void set_model_file_path(string path);

  void draw(ModelConfig *model_config);
};
#endif