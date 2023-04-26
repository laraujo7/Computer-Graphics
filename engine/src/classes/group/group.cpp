#include "group.hpp"

Group::Group() {}

Group::Group(vector<pair<string, ModelConfig *>> file_paths,
             vector<Group *> sub_groups,
             vector<pair<string, Transformation *>> transformations) {
  this->file_paths = file_paths;
  this->sub_groups = sub_groups;
  this->transformations = transformations;
}

vector<pair<string, ModelConfig *>> Group::get_file_paths() {
  return this->file_paths;
}

vector<Group *> Group::get_sub_groups() { return this->sub_groups; }

vector<pair<string, Transformation *>> Group::get_transformations() {
  return this->transformations;
}

void Group::set_file_paths(vector<pair<string, ModelConfig *>> file_paths) {
  this->file_paths = file_paths;
}

void Group::set_sub_groups(vector<Group *> sub_groups) {
  this->sub_groups = sub_groups;
}

void Group::set_transformations(
    vector<pair<string, Transformation *>> transformations) {
  this->transformations = transformations;
}

void Group::add_file_path(string file_path, ModelConfig *model_config) {
  (this->file_paths).push_back(make_pair(file_path, model_config));
}

void Group::add_sub_group(Group *sub_group) {
  (this->sub_groups).push_back(sub_group);
}

void Group::add_transformation(string transformation_type,
                               Transformation *transformation) {
  (this->transformations)
      .push_back(make_pair(transformation_type, transformation));
}

void Group::add_transformation(string transformation_type, float angle, float x,
                               float y, float z) {
  (this->transformations)
      .push_back(
          make_pair(transformation_type, new Transformation(angle, x, y, z)));
}

void Group::add_transformation(string transformation_type, int time, bool align, vector<Point> control_points) {
  (this->transformations)
      .push_back(
          make_pair(transformation_type, new Transformation(time, align, Spline(control_points))));
}

void Group::add_transformation(string transformation_type, float x, float y,
                               float z) {
  (this->transformations)
      .push_back(make_pair(transformation_type, new Transformation(x, y, z)));
}

void Group::draw_trajectory() {

  for (pair<string, Transformation *> transformation : this->get_transformations()) {
        switch (get_xml_tag(transformation.first)) {
          case XMLTags::TRANSLATE: {
            int no_points = transformation.second->get_spline_size();
            int t = 0;
            glBegin(GL_LINES);
              		glColor3f(0.0f, 1.0f, 0.0f);
                  for(int i=0; i<(100*no_points); ++i, t+=100){
                    Point p1 = transformation.second->get_translate(t);
                    Point p2 = transformation.second->get_translate(t+100);
                    glVertex3f(p1.get_x(), p1.get_y(), p1.get_z());
                    glVertex3f(p2.get_x(), p2.get_y(), p2.get_z());
                  }
            glEnd();

          } break;

          default:
            break;
    }
  }
}

void Group::draw(unordered_map<string, Model3D *> models, int elapsed_time, bool trajectory) {
  if(trajectory) draw_trajectory();

  glPushMatrix();

  for (pair<string, Transformation *> transformation :
       this->get_transformations()) {

    switch (get_xml_tag(transformation.first)) {
    case XMLTags::TRANSLATE: {
      transformation.second->get_translate(elapsed_time);
    } break;

    case XMLTags::SCALE: {
      tuple<float, float, float> scale = transformation.second->get_scale();
      glScalef(get<0>(scale), get<1>(scale), get<2>(scale));
    } break;

    case XMLTags::ROTATE: {
      tuple<float, float, float, float> rotate =
          transformation.second->get_rotate();
      glRotatef(get<0>(rotate), get<1>(rotate), get<2>(rotate), get<3>(rotate));
    } break;

    default:
      break;
    }
  }

  for (pair<string, ModelConfig *> file_path : this->file_paths) {
    models[file_path.first]->draw(file_path.second);
  }

  for (Group *sub_group : this->sub_groups) {
    sub_group->draw(models, elapsed_time, trajectory);
  }

  glPopMatrix();
}