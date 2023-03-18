#include "world.hpp"

World::World() {}

World::World(int window_width, int window_height, list<Model3D *> models,
             Model3D *model, Camera *camera) {
  this->window_width = window_width;
  this->window_height = window_height;
  this->models = models;
  this->model = model;
  this->camera = camera;
}

int World::get_window_width() { return this->window_width; };

int World::get_window_height() { return this->window_height; };

list<Model3D *> World::get_models() { return this->models; }

Model3D *World::get_model() { return this->model; }

Camera *World::get_camera() { return this->camera; }

void World::set_window_width(int window_width) {
  this->window_width = window_width;
}

void World::set_window_height(int window_height) {
  this->window_height = window_height;
}

void World::set_models(list<Model3D *> models) { this->models = models; }

void World::set_camera(Camera *camera) { this->camera = camera; }

void World::load_XML(char *file_path) {
  XMLDocument doc;

  bool load_ok = doc.LoadFile(file_path);
  XMLElement *world_element = doc.RootElement();

  if (load_ok == XML_SUCCESS) {
    parse_world(world_element);
  } else {
    println("Erro ao ler ficheiro de configuração XML-> ", file_path);
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
      parse_group(world_children);
    } break;

    default:
      break;
    }
  }
}

void World::parse_window(XMLElement *window_element) {
  int width = atoi(window_element->Attribute("width"));
  int height = atoi(window_element->Attribute("height"));

  if (width > 0 && height > 0) {
    glutReshapeWindow(width, height);
  };
}

void World::parse_camera(XMLElement *camera_element) {
  for (XMLElement *camera_children = camera_element->FirstChildElement();
       camera_children;
       camera_children = camera_children->NextSiblingElement()) {
    string camera_attribute = camera_children->Name();

    if (!camera_attribute.compare("position") ||
        !camera_attribute.compare("look_at") ||
        !camera_attribute.compare("up")) {
      float x = stof(camera_children->Attribute("x"));
      float y = stof(camera_children->Attribute("y"));
      float z = stof(camera_children->Attribute("z"));

      if (!camera_attribute.compare("position")) {
        this->camera->set_position(x, y, z);
      } else if (!camera_attribute.compare("look_at")) {
        this->camera->set_look_at(x, y, z);
      } else if (!camera_attribute.compare("up")) {
        this->camera->set_up(x, y, z);
      }
    } else if (!camera_attribute.compare("projection")) {
      float fov = stof(camera_children->Attribute("fov"));
      float near = stof(camera_children->Attribute("near"));
      float far = stof(camera_children->Attribute("far"));

      this->camera->set_projection(fov, near, far);
    }
  }
}

void World::parse_lights(XMLElement *lights_element) {}

void World::parse_group(XMLElement *group_element) {
  if (group_element->FirstChildElement("transform")) {
    println("[transform] only required from phase 2");
  }
  if (group_element->FirstChildElement("models") != NULL) {
    load_models(group_element->FirstChildElement("models"));
  }
}

void World::load3D_model(XMLElement *model_elem) {
  string file_path = model_elem->Attribute("file");

  this->model = new Model3D(file_path);
}

void World::load_models(XMLElement *models_elem) {
  load3D_model(models_elem->FirstChildElement("model"));
}
