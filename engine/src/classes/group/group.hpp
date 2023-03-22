#ifndef GROUP_H
#define GROUP_H

#include "../../../utils/xml_parser_helpers/xml_parser_helpers.hpp"
#include "../model3d/model3d.hpp"

#include <unordered_map>
#include <vector>

class Group {
private:
  vector<string> file_paths;
  vector<Group *> sub_groups;
  vector<pair<string, tuple<float, float, float, float>>> transformations;

public:
  Group();

  Group(
      vector<string> file_paths, vector<Group *> sub_groups,
      vector<pair<string, tuple<float, float, float, float>>> transformations);

  vector<string> get_file_paths();

  vector<Group *> get_sub_groups();

  vector<pair<string, tuple<float, float, float, float>>> get_transformations();

  void set_file_paths(vector<string> file_paths);

  void set_sub_groups(vector<Group *> sub_groups);

  void set_transformations(
      vector<pair<string, tuple<float, float, float, float>>> transformations);

  void add_file_path(string file_path);

  void add_sub_group(Group *sub_group);

  void add_transformation(string transformation_type,
                          tuple<float, float, float, float> transformation);

  void add_transformation(string transformation_type, float angle, float x,
                          float y, float z);

  void add_transformation(string transformation_type, float x, float y,
                          float z);

  void draw(unordered_map<string, Model3D *> models);
};
#endif
