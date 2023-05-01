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

  if (load_ok == XML_SUCCESS) {
    parse_world(doc.RootElement());
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

    case XMLTags::GROUP:
      this->groups.push_back(parse_group(world_children));
      break;

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

    case XMLTags::TRANSLATE: {

      int time = transform_children->IntAttribute("time");
      if (time != 0) {
        bool align = transform_children->BoolAttribute("align");
        // cria vetor de 4 pontos
        vector<Point> control_points;
        // loop que lê 4 atributos "point"

        for (XMLElement *translate_point =
                 transform_children->FirstChildElement();
             translate_point;
             translate_point = translate_point->NextSiblingElement()) {

          x = translate_point->FloatAttribute("x");
          y = translate_point->FloatAttribute("y");
          z = translate_point->FloatAttribute("z");

          control_points.push_back(Point(x, y, z));
        }

        group->add_transformation(str_transform, time, align, control_points);
      } else {
        group->add_transformation(str_transform, x, y, z);
      }
    } break;

    case XMLTags::SCALE:
      group->add_transformation(str_transform, x, y, z);
      break;
    case XMLTags::ROTATE: {
      float angle = transform_children->FloatAttribute("angle");
      int time = transform_children->IntAttribute("time");
      if (time != 0)
        group->add_transformation(str_transform, time, x, y, z);
      else
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
    string str_models = models_children->Name();

    if (!(str_models).compare("model")) {
      ModelConfig *model_config = new ModelConfig();
      string file_path = models_children->Attribute("file");
      const char *color = models_children->Attribute("color");

      if (color != NULL)
        model_config->set_color((string)color);

      parse_model(models_children, model_config);

      this->add_model(file_path, new Model3D(file_path));
      group->add_file_path(file_path, model_config);
    }
  }
}

void World::parse_model(XMLElement *model_element, ModelConfig *model_config) {
  for (XMLElement *model_children = model_element->FirstChildElement();
       model_children; model_children = model_children->NextSiblingElement()) {
    string str_model = model_children->Name();

    switch (get_xml_tag(str_model)) {
    case XMLTags::COLOR:
      parse_color(model_children, model_config);
      break;

    case XMLTags::TEXTURE: {
      string texture_file_path = model_children->Attribute("file");
      model_config->set_texture_file_path(texture_file_path);
    } break;

    default:
      break;
    }
  }
}

void World::parse_color(XMLElement *color_element, ModelConfig *model_config) {
  for (XMLElement *color_children = color_element->FirstChildElement();
       color_children; color_children = color_children->NextSiblingElement()) {
    string str_color = color_children->Name();

    switch (get_xml_tag(str_color)) {
    case XMLTags::DIFFUSE:
    case XMLTags::AMBIENT:
    case XMLTags::SPECULAR:
    case XMLTags::EMISSIVE: {
      float r = color_children->FloatAttribute("R");
      float g = color_children->FloatAttribute("G");
      float b = color_children->FloatAttribute("B");

      if (!str_color.compare("diffuse")) {
        model_config->set_diffuse(r, g, b);
      } else if (!str_color.compare("ambient")) {
        model_config->set_ambient(r, g, b);
      } else if (!str_color.compare("specular")) {
        model_config->set_specular(r, g, b);
      } else {
        model_config->set_emissive(r, g, b);
      }

    } break;

    case XMLTags::SHININESS: {
      int shininess = color_children->IntAttribute("value");
      model_config->set_shininess(shininess);
    } break;

    default:
      break;
    }
  }
}

void World::draw(int elapsed_time, bool trajectory) {
  for (Group *group : this->groups) {
    group->draw(this->get_models(), elapsed_time, trajectory);
  }
}
