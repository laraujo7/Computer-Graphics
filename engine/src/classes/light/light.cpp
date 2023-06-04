#include "light.hpp"

Light::Light() {}

Light::Light(int light_index, string light_type, float x, float y, float z) {
  this->light_type = get_light_type(light_type);
  this->light_index = light_index;

  switch (this->light_type) {
  case LightType::POINT: {
    this->position = make_tuple(x, y, z, 1.0);
  } break;
  case LightType::DIRECTIONAL: {
    this->direction = make_tuple(x, y, z, 0.0);
  } break;
  }

  enable_light();
  setup_light();
}

Light::Light(int light_index, string light_type, float posX, float posY,
             float posZ, float dirX, float dirY, float dirZ, float cutoff) {
  this->light_type = get_light_type(light_type);
  this->light_index = light_index;
  this->position = make_tuple(posX, posY, posZ, 1.0);
  this->direction = make_tuple(dirX, dirY, dirZ, 0.0);
  this->cutoff = cutoff;

  enable_light();
  setup_light();
}

void Light::enable_light() { glEnable(GL_LIGHT0 + this->light_index); }

void Light::setup_light() {
  float dark[4] = {0.2, 0.2, 0.2, 1.0};
  float white[4] = {1.0, 1.0, 1.0, 1.0};
  float black[4] = {0.0f, 0.0f, 0.0f, 0.0f};
  // light colors
  glLightfv(GL_LIGHT0 + this->light_index, GL_AMBIENT, dark);
  glLightfv(GL_LIGHT0 + this->light_index, GL_DIFFUSE, white);
  glLightfv(GL_LIGHT0 + this->light_index, GL_SPECULAR, white);

  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, black);
}

void Light::draw() {
  switch (this->light_type) {
  case LightType::POINT: {
    glLightfv(GL_LIGHT0 + this->light_index, GL_POSITION,
              tupleToArray(this->position));
  } break;

  case LightType::DIRECTIONAL: {
    glLightfv(GL_LIGHT0 + this->light_index, GL_POSITION,
              tupleToArray(this->direction));
  } break;

  case LightType::SPOTLIGHT: {
    glLightfv(GL_LIGHT0 + this->light_index, GL_POSITION,
              tupleToArray(this->position));
    glLightfv(GL_LIGHT0 + this->light_index, GL_SPOT_DIRECTION,
              tupleToArray(this->direction));
    glLightf(GL_LIGHT0 + this->light_index, GL_SPOT_CUTOFF, this->cutoff);
  } break;
  }
}