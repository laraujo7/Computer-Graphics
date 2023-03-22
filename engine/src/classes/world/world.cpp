#include "world.hpp"

World::World() {}

World::World(int window_width, int window_height,
             unordered_map<string, Model3D *> models, vector<Group *> groups,
             Camera *camera) {
  this->window_width = window_width;
  this->window_height = window_height;
  this->models = models;
  this->groups = groups;
  this->camera = camera;
}

int World::get_window_width() { return this->window_width; };

int World::get_window_height() { return this->window_height; };

vector<Group *> World::get_groups() { return this->groups; }

unordered_map<string, Model3D *> World::get_models() { return this->models; }

Model3D *World::get_model(string file_path) { return this->models[file_path]; }

Camera *World::get_camera() { return this->camera; }

void World::set_window_width(int window_width) {
  this->window_width = window_width;
}

void World::set_window_height(int window_height) {
  this->window_height = window_height;
}

void World::set_groups(vector<Group *> groups) { this->groups = groups; }

void World::set_models(unordered_map<string, Model3D *> models) {
  this->models = models;
}

void World::set_camera(Camera *camera) { this->camera = camera; }

void World::add_model(string file_path, Model3D *model) {
  this->models[file_path] = model;
}

void World::load_XML(char *file_path) {
  XMLDocument doc;

  bool load_ok = doc.LoadFile(file_path);
  XMLElement *world_element = doc.RootElement();

  if (load_ok == XML_SUCCESS) {
    parse_world(world_element);
  } else {
    println("Error when reading XML configuration file-> ", file_path);
  }
}

void World::parse_world(XMLElement *world_element) {
  for (XMLElement *world_children = world_element->FirstChildElement();
       world_children; world_children = world_children->NextSiblingElement()) {

    switch (get_xml_tag(world_children->Value())) {
    case XMLTags::WINDOW:
      parse_window(world_children);
      break;

    case XMLTags::CAMERA:
      parse_camera(world_children);
      break;

    case XMLTags::LIGHTS:
      parse_lights(world_children);
      break;

    case XMLTags::GROUP: {
      this->groups.push_back(parse_group(world_children));
    } break;

    default:
      break;
    }
  }
}

void World::parse_window(XMLElement *window_element) {
  int width = window_element->IntAttribute("width");
  int height = window_element->IntAttribute("height");

  if (width > 0 && height > 0) {
    this->window_width = width;
    this->window_height = height;
    glutReshapeWindow(width, height);
  };
}

void World::parse_camera(XMLElement *camera_element) {
  for (XMLElement *camera_children = camera_element->FirstChildElement();
       camera_children;
       camera_children = camera_children->NextSiblingElement()) {
    string str_camera_children_tag = camera_children->Name();

    switch (get_xml_tag(str_camera_children_tag)) {
    case XMLTags::POSITION:
    case XMLTags::LOOKAT:
    case XMLTags::UP: {
      float x = camera_children->FloatAttribute("x");
      float y = camera_children->FloatAttribute("y");
      float z = camera_children->FloatAttribute("z");

      if (!str_camera_children_tag.compare("position")) {
        this->camera->set_position(x, y, z);
      } else if (!str_camera_children_tag.compare("lookAt")) {
        this->camera->set_look_at(x, y, z);
      } else {
        this->camera->set_up(x, y, z);
      }
    } break;
    case PROJECTION: {
      float fov = camera_children->FloatAttribute("fov");
      float near = camera_children->FloatAttribute("near");
      float far = camera_children->FloatAttribute("far");

      this->camera->set_projection(fov, near, far);
    } break;
    default:
      break;
    }
  }
}

void World::parse_lights(XMLElement *lights_element) {}

Group *World::parse_group(XMLElement *group_element) {
  Group *group = new Group();

  for (XMLElement *group_children = group_element->FirstChildElement();
       group_children; group_children = group_children->NextSiblingElement()) {

    switch (get_xml_tag(group_children->Name())) {
    case XMLTags::TRANSFORM:
      parse_transform(group_children, group);
      break;
    case XMLTags::MODELS:
      parse_models(group_children, group);
      break;
    case XMLTags::GROUP:
      group->add_sub_group(parse_group(group_children));
      break;
    default:
      break;
    }
  }

  return group;
}

void World::parse_transform(XMLElement *transform_element, Group *group) {

  for (XMLElement *transform_children = transform_element->FirstChildElement();
       transform_children;
       transform_children = transform_children->NextSiblingElement()) {
    string str_transform = transform_children->Name();
    float x = transform_children->FloatAttribute("x");
    float y = transform_children->FloatAttribute("y");
    float z = transform_children->FloatAttribute("z");

    switch (get_xml_tag(str_transform)) {
    case XMLTags::TRANSLATE:
    case XMLTags::SCALE:
      group->add_transformation(str_transform, x, y, z);
      break;
    case XMLTags::ROTATE: {
      float angle = transform_children->FloatAttribute("angle");
      group->add_transformation(str_transform, angle, x, y, z);
    } break;
    default:
      break;
    }
  }
}

void World::parse_models(XMLElement *models_element, Group *group) {
  for (XMLElement *models_children = models_element->FirstChildElement();
       models_children;
       models_children = models_children->NextSiblingElement()) {

    if (!((string)models_children->Name()).compare("model")) {
      string file_path = models_children->Attribute("file");
      this->add_model(file_path, new Model3D(file_path));
      group->add_file_path(file_path);
    }
  }
}

void World::draw() {
  for (Group *group : this->groups) {
    group->draw(this->get_models());
  }
}
