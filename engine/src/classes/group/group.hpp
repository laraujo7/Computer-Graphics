#ifndef GROUP_H
#define GROUP_H

#include "../../../utils/xml_parser_helpers/xml_parser_helpers.hpp"
#include "../model3d/model3d.hpp"
#include "../modelConfig/modelConfig.hpp"
#include "../transformation/transformation.hpp"

#include <unordered_map>
#include <vector>

class Group {
private:
  vector<pair<string, ModelConfig *>> file_paths;
  vector<Group *> sub_groups;
  vector<pair<string, Transformation *>> transformations;

public:
  Group();

  Group(vector<pair<string, ModelConfig *>> file_paths,
        vector<Group *> sub_groups,
        vector<pair<string, Transformation *>> transformations);

  vector<pair<string, ModelConfig *>> get_file_paths();

  vector<Group *> get_sub_groups();

  vector<pair<string, Transformation *>> get_transformations();

  void set_file_paths(vector<pair<string, ModelConfig *>> file_paths);

  void set_sub_groups(vector<Group *> sub_groups);

  void
  set_transformations(vector<pair<string, Transformation *>> transformations);

  void add_file_path(string file_path, ModelConfig *model_config);

  void add_sub_group(Group *sub_group);

  void add_transformation(string transformation_type,
                          Transformation *transformation);

  void add_transformation(string transformation_type, float angle, float x,
                          float y, float z);

  void add_transformation(string transformation_type, float x, float y,
                          float z);

  void draw(unordered_map<string, Model3D *> models, int elapsed_time);
};
#endif
