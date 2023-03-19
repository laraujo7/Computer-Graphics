#include "group.hpp"

Group::Group() {}

Group::Group(
    vector<string> file_paths, vector<Group *> sub_groups,
    vector<pair<string, tuple<float, float, float, float>>> transformations) {
  this->file_paths = file_paths;
  this->sub_groups = sub_groups;
  this->transformations = transformations;
}

vector<string> Group::get_file_paths() { return this->file_paths; }

vector<Group *> Group::get_sub_groups() { return this->sub_groups; }

vector<pair<string, tuple<float, float, float, float>>>
Group::get_transformations() {
  return this->transformations;
}

void Group::set_file_paths(vector<string> file_paths) {
  this->file_paths = file_paths;
}

void Group::set_sub_groups(vector<Group *> sub_groups) {
  this->sub_groups = sub_groups;
}

void Group::set_transformations(
    vector<pair<string, tuple<float, float, float, float>>> transformations) {
  this->transformations = transformations;
}

void Group::add_file_path(string file_path) {
  (this->file_paths).push_back(file_path);
}

void Group::add_sub_group(Group *sub_group) {
  (this->sub_groups).push_back(sub_group);
}

void Group::add_transformation(
    string transformation_type,
    tuple<float, float, float, float> transformation) {
  (this->transformations)
      .push_back(make_pair(transformation_type, transformation));
}

void Group::add_transformation(string transformation_type, float angle, float x,
                               float y, float z) {
  (this->transformations)
      .push_back(make_pair(transformation_type, make_tuple(angle, x, y, z)));
}

void Group::add_transformation(string transformation_type, float x, float y,
                               float z) {
  (this->transformations)
      .push_back(make_pair(transformation_type, make_tuple(x, y, z, 0)));
}

void Group::draw(unordered_map<string, Model3D *> models) {
  glPushMatrix();

  for (pair<string, tuple<float, float, float, float>> transformation :
       this->get_transformations()) {
    switch (get_xml_tag(transformation.first)) {
    case XMLTags::TRANSLATE:
      glTranslatef(get<0>(transformation.second), get<1>(transformation.second),
                   get<2>(transformation.second));
      break;
    case XMLTags::SCALE:
      glScalef(get<0>(transformation.second), get<1>(transformation.second),
               get<2>(transformation.second));
      break;
    case XMLTags::ROTATE:
      glRotatef(get<0>(transformation.second), get<1>(transformation.second),
                get<2>(transformation.second), get<3>(transformation.second));
      break;
    default:
      break;
    }
  }

  for (string file_path : this->file_paths) {
    models[file_path]->draw();
  }

  for (Group *sub_group : this->sub_groups) {
    sub_group->draw(models);
  }

  glPopMatrix();
}