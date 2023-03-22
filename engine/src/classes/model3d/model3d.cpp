#include "model3d.hpp"

string DEFAULT_FILE_PATH = "models/";

Model3D::Model3D() {}

Model3D::Model3D(const Model3D &model) {
  this->model_file_path = model.model_file_path;
  this->texture_file_path = model.texture_file_path;
  this->diffuse = model.diffuse;
  this->ambient = model.ambient;
  this->specular = model.specular;
  this->emissive = model.emissive;
  this->shininess = model.shininess;
  read_file(model.model_file_path);
}

Model3D::Model3D(string model_file_path, string texture_file_path,
                 tuple<int, int, int> diffuse, tuple<int, int, int> ambient,
                 tuple<int, int, int> specular, tuple<int, int, int> emissive,
                 int shininess) {
  this->model_file_path = model_file_path;
  this->texture_file_path = texture_file_path;
  this->diffuse = diffuse;
  this->ambient = ambient;
  this->specular = specular;
  this->emissive = emissive;
  this->shininess = shininess;
  read_file(model_file_path);
}

Model3D::Model3D(string model_file_path) {
  this->model_file_path = model_file_path;
  read_file(model_file_path);
}

string Model3D::get_model_file_path() { return this->model_file_path; }

string Model3D::get_texture_filepPath() { return this->texture_file_path; }

tuple<int, int, int> Model3D::get_diffuse() { return this->diffuse; }

tuple<int, int, int> Model3D::get_ambient() { return this->ambient; }

tuple<int, int, int> Model3D::get_specular() { return this->specular; }

tuple<int, int, int> Model3D::get_emissive() { return this->emissive; }

int Model3D::get_shininess() { return this->shininess; }

void Model3D::set_model_file_path(string path) { this->model_file_path = path; }

void Model3D::set_texture_file_path(string path) {
  this->texture_file_path = path;
}

void Model3D::set_diffuse(tuple<int, int, int> diffuse) {
  this->diffuse = diffuse;
}

void Model3D::set_diffuse(int r, int g, int b) {
  this->diffuse = make_tuple(r, g, b);
}

void Model3D::set_ambient(tuple<int, int, int> ambient) {
  this->ambient = ambient;
}

void Model3D::set_ambient(int r, int g, int b) {
  this->ambient = make_tuple(r, g, b);
}

void Model3D::set_specular(tuple<int, int, int> specular) {
  this->specular = specular;
}

void Model3D::set_specular(int r, int g, int b) {
  this->specular = make_tuple(r, g, b);
}

void Model3D::set_emissive(tuple<int, int, int> emissive) {
  this->emissive = emissive;
}

void Model3D::set_emissive(int r, int g, int b) {
  this->emissive = make_tuple(r, g, b);
}

void Model3D::set_shininess(int shininess) { this->shininess = shininess; }

string Model3D::model_to_string() {
  return "FILEPATH: " + this->model_file_path + "\n" +
         "TEXTURE: " + this->texture_file_path + "\n" +
         "DIFFUSE: " + to_string(get<0>(this->diffuse)) + " " +
         to_string(get<1>(this->diffuse)) + " " +
         to_string(get<2>(this->diffuse)) + "\n" +
         "AMBIENT: " + to_string(get<0>(this->ambient)) + " " +
         to_string(get<1>(this->ambient)) + " " +
         to_string(get<2>(this->ambient)) + "\n" +
         "SPECULAR: " + to_string(get<0>(this->specular)) + " " +
         to_string(get<1>(this->specular)) + " " +
         to_string(get<2>(this->specular)) + "\n" +
         "EMISSIVE: " + to_string(get<0>(this->emissive)) + " " +
         to_string(get<1>(this->emissive)) + " " +
         to_string(get<2>(this->emissive)) + "\n" +
         "SHININESS: " + to_string(this->shininess);
}

void Model3D::read_file(string file_path) {
  float x, y, z;
  int i1, i2, i3;
  vector<float> points;
  vector<unsigned int> indexes;

  ifstream file(DEFAULT_FILE_PATH + file_path);

  if (file.is_open()) {
    string model = get_file_line(file);

    int num_ponts = stoi(get_file_line(file));

    for (int i = 0; i < num_ponts; i++) {
      string str_points = get_file_line(file);
      if (sscanf(str_points.c_str(), "%f %f %f", &x, &y, &z) == 3) {
        points.push_back(x);
        points.push_back(y);
        points.push_back(z);
      } else {
        perrorln("Invalid input: ", str_points);
      }
    }

    int num_triangles = stoi(get_file_line(file));

    for (int i = 0; i < num_triangles; i++) {
      string str_indexes = get_file_line(file);
      if (sscanf(str_indexes.c_str(), "%d %d %d", &i1, &i2, &i3) == 3) {
        indexes.push_back(i1);
        indexes.push_back(i2);
        indexes.push_back(i3);
      } else {
        perrorln("Invalid input: ", str_indexes);
      }
    }

    file.close();

    this->num_indexs = num_triangles * 3;

    glGenBuffers(1, &(this->vertices));
    glBindBuffer(GL_ARRAY_BUFFER, this->vertices);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * points.size(), points.data(),
                 GL_STATIC_DRAW);

    glGenBuffers(1, &(this->indices));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indices);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indexes.size(),
                 indexes.data(), GL_STATIC_DRAW);
  }
}

void Model3D::draw() {

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBindBuffer(GL_ARRAY_BUFFER, this->vertices);
  glVertexPointer(3, GL_FLOAT, 0, 0);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indices);

  // with fill
  glDrawElements(GL_TRIANGLES, this->num_indexs, GL_UNSIGNED_INT, NULL);

  // wireframe
  // glDrawElements(GL_LINES, index_count, GL_UNSIGNED_INT, NULL);
}