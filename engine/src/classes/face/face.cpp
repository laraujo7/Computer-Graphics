#include "face.hpp"

Face::Face() {}

Face::Face(const Face &face) {
  this->vertice_indeces = face.vertice_indeces;
  this->texture_indeces = face.texture_indeces;
  this->normal = face.normal;
}

Face::Face(vector<int> vertice_indeces, vector<int> texture_indeces,
           int normal = -1) {
  this->vertice_indeces = vertice_indeces;
  this->texture_indeces = texture_indeces;
  this->normal = normal;
}

vector<int> Face::get_vertice_indeces() { return this->vertice_indeces; }

vector<int> Face::get_texture_indeces() { return this->texture_indeces; }

int Face::get_normal() { return this->normal; }

void Face::set_vertice_indeces(vector<int> vertice_indeces) {
  this->vertice_indeces = vertice_indeces;
}

void Face::set_texture_indeces(vector<int> texture_indeces) {
  this->texture_indeces = texture_indeces;
}

void Face::set_normal(int normal) { this->normal = normal; }

void Face::add_vertice_index(int vertice_index) {
  this->vertice_indeces.push_back(vertice_index);
}

void Face::add_texture_index(int texture_index) {
  this->texture_indeces.push_back(texture_index);
}