#ifndef WORLD_H
#define WORLD_H

#include "../../../../utils/generic_functions/generic_functions.hpp"
#include "../../../lib/tinyxml2/tinyxml2.h"
#include "../camera/camera.hpp"
#include "../group/group.hpp"
#include "../model3d/model3d.hpp"
#include "../modelConfig/modelConfig.hpp"

#include <unordered_map>
#include <vector>

using namespace tinyxml2;
using namespace std;

class World {
private:
  // window
  int window_width;
  int window_height;

  unordered_map<string, Model3D *> models;
  vector<Group *> groups;
  Camera *camera = new Camera();

  void parse_world(XMLElement *world_element);
  void parse_window(XMLElement *window_element);
  void parse_camera(XMLElement *camera_elem);
  void parse_lights(XMLElement *lights_element);
  Group *parse_group(XMLElement *group_element);
  void parse_transform(XMLElement *transform_element, Group *group);
  void parse_models(XMLElement *models_element, Group *group);
  void parse_model(XMLElement *model_element, ModelConfig *model_config);
  void parse_color(XMLElement *color_element, ModelConfig *model_config);

public:
  World();

  World(int window_width, int window_height,
        unordered_map<string, Model3D *> models, vector<Group *> groups,
        Camera *camera);

  int get_window_width();

  int get_window_height();

  vector<Group *> get_groups();

  unordered_map<string, Model3D *> get_models();

  Model3D *get_model(string file_path);

  Camera *get_camera();

  void set_window_width(int window_width);

  void set_window_height(int window_height);

  void set_groups(vector<Group *> groups);

  void set_models(unordered_map<string, Model3D *> models);

  void set_camera(Camera *camera);

  void add_model(string file_path, Model3D *model);

  void load_XML(char *file_path);

  void draw(int elapsed_time);
};
#endif