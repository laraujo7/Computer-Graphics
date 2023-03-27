#include "model3d.hpp"

string DEFAULT_FILE_PATH = "models/";

Model3D::Model3D() {}

Model3D::Model3D(const Model3D &model) {
  this->model_file_path = model.model_file_path;
  read_file(model.model_file_path);
}

Model3D::Model3D(string model_file_path) {
  this->model_file_path = model_file_path;
  read_file(model_file_path);
}

string Model3D::get_model_file_path() { return this->model_file_path; }

void Model3D::set_model_file_path(string path) { this->model_file_path = path; }

void Model3D::read_file(string file_path) {
  ifstream file(DEFAULT_FILE_PATH + file_path);

  if (!file.is_open()) {
    println("Couldn't open the provided file");
    return;
  }

  float x, y, z;
  int i1, i2, i3;
  vector<float> points;
  vector<unsigned int> indexes;

  string model_name = get_file_line(file);

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

void Model3D::draw(ModelConfig *model_config) {

  set_glcolor3f(model_config->get_color());
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBindBuffer(GL_ARRAY_BUFFER, this->vertices);
  glVertexPointer(3, GL_FLOAT, 0, 0);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indices);

  // with fill
  glDrawElements(GL_TRIANGLES, this->num_indexs, GL_UNSIGNED_INT, NULL);
}