#ifndef MODELOBJ_H
#define MODELOBJ_H

#include "../../../../utils/file_helpers/file_helpers.hpp"
#include "../../../../utils/generic_functions/generic_functions.hpp"
#include "../../../../utils/string_helpers/string_helpers.hpp"
#include "../../../lib/glew/glew.h"
#include "../../../utils/colors_helpers/colors_helpers.hpp"
#include "../../../utils/obj_parser_helpers/obj_parser_helpers.hpp"
#include "../face/face.hpp"
#include "../modelConfig/modelConfig.hpp"

#include <GL/glut.h>
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ModelObj {
private:
  string model_file_path;

  GLuint list;

  void read_file(string file_path);

public:
  ModelObj();

  ModelObj(const ModelObj &model);

  ModelObj(string model_file_path);

  string get_model_file_path();

  void set_model_file_path(string path);

  void draw(ModelConfig *model_config);
};
#endif