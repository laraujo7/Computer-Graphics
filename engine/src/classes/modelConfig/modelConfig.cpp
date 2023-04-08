#include "modelConfig.hpp"

ModelConfig::ModelConfig() {}

ModelConfig::ModelConfig(string texture_file_path, string color,
                         tuple<int, int, int> diffuse,
                         tuple<int, int, int> ambient,
                         tuple<int, int, int> specular,
                         tuple<int, int, int> emissive, int shininess) {
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

tuple<int, int, int> ModelConfig::get_diffuse() { return this->diffuse; }

tuple<int, int, int> ModelConfig::get_ambient() { return this->ambient; }

tuple<int, int, int> ModelConfig::get_specular() { return this->specular; }

tuple<int, int, int> ModelConfig::get_emissive() { return this->emissive; }

int ModelConfig::get_shininess() { return this->shininess; }

void ModelConfig::set_texture_file_path(string path) {
  this->texture_file_path = path;
}

void ModelConfig::set_color(string color) { this->color = color; }

void ModelConfig::set_diffuse(tuple<int, int, int> diffuse) {
  this->diffuse = diffuse;
}

void ModelConfig::set_diffuse(int r, int g, int b) {
  this->diffuse = make_tuple(r, g, b);
}

void ModelConfig::set_ambient(tuple<int, int, int> ambient) {
  this->ambient = ambient;
}

void ModelConfig::set_ambient(int r, int g, int b) {
  this->ambient = make_tuple(r, g, b);
}

void ModelConfig::set_specular(tuple<int, int, int> specular) {
  this->specular = specular;
}

void ModelConfig::set_specular(int r, int g, int b) {
  this->specular = make_tuple(r, g, b);
}

void ModelConfig::set_emissive(tuple<int, int, int> emissive) {
  this->emissive = emissive;
}

void ModelConfig::set_emissive(int r, int g, int b) {
  this->emissive = make_tuple(r, g, b);
}

void ModelConfig::set_shininess(int shininess) { this->shininess = shininess; }