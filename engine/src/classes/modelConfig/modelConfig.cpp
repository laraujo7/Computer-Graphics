#include "modelConfig.hpp"

ModelConfig::ModelConfig() {}

ModelConfig::ModelConfig(string texture_file_path, string color,
                         tuple<float, float, float> diffuse,
                         tuple<float, float, float> ambient,
                         tuple<float, float, float> specular,
                         tuple<float, float, float> emissive, float shininess) {
  this->texture_file_path = texture_file_path;
  this->color = color;
  this->diffuse = diffuse;
  this->ambient = ambient;
  this->specular = specular;
  this->emissive = emissive;
  this->shininess = shininess;
}

string ModelConfig::get_texture_file_path() { return this->texture_file_path; }

string ModelConfig::get_color() { return this->color; }

tuple<float, float, float> ModelConfig::get_diffuse() { return this->diffuse; }

tuple<float, float, float> ModelConfig::get_ambient() { return this->ambient; }

tuple<float, float, float> ModelConfig::get_specular() {
  return this->specular;
}

tuple<float, float, float> ModelConfig::get_emissive() {
  return this->emissive;
}

float ModelConfig::get_shininess() { return this->shininess; }

void ModelConfig::set_texture_file_path(string path) {
  this->texture_file_path = path;
}

void ModelConfig::set_color(string color) { this->color = color; }

void ModelConfig::set_diffuse(tuple<float, float, float> diffuse) {
  this->diffuse = diffuse;
}

void ModelConfig::set_diffuse(float r, float g, float b) {
  this->diffuse = make_tuple(r, g, b);
}

void ModelConfig::set_ambient(tuple<float, float, float> ambient) {
  this->ambient = ambient;
}

void ModelConfig::set_ambient(float r, float g, float b) {
  this->ambient = make_tuple(r, g, b);
}

void ModelConfig::set_specular(tuple<float, float, float> specular) {
  this->specular = specular;
}

void ModelConfig::set_specular(float r, float g, float b) {
  this->specular = make_tuple(r, g, b);
}

void ModelConfig::set_emissive(tuple<float, float, float> emissive) {
  this->emissive = emissive;
}

void ModelConfig::set_emissive(float r, float g, float b) {
  this->emissive = make_tuple(r, g, b);
}

void ModelConfig::set_shininess(float shininess) {
  this->shininess = shininess;
}