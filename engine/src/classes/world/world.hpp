#ifndef WORLD_H
#define WORLD_H

#include "../../../../utils/generic_functions.hpp"
#include "../../../lib/tinyxml2/tinyxml2.h"
#include "../../../utils/xml_parser_helpers/xml_parser_helpers.hpp"
#include "../camera/camera.hpp"
#include "../model3d/model3d.hpp"

#include <list>

using namespace tinyxml2;

class World {
private:
  // window
  int window_width;
  int window_height;

  list<Model3D *> models;
  Model3D *model;
  Camera *camera = new Camera();

  void parse_world(XMLElement *world_element);
  void parse_window(XMLElement *window_element);
  void parse_camera(XMLElement *camera_elem);
  void parse_lights(XMLElement *lights_element);
  void parse_group(XMLElement *group_element);
  void load3D_model(XMLElement *model_elem);
  void load_models(XMLElement *models_elem);

public:
  World();

  World(int window_width, int window_height, list<Model3D *> models,
        Model3D *model, Camera *camera);

  int get_window_width();

  int get_window_height();

  list<Model3D *> get_models();

  Model3D *get_model();

  Camera *get_camera();

  void set_window_width(int window_width);

  void set_window_height(int window_height);

  void set_models(list<Model3D *> models);

  void set_camera(Camera *camera);

  void load_XML(char *file_path);
};
#endif