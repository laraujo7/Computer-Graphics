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
  vector<float> normals;
  vector<float> texture_coordinates;

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

  string line = get_file_line(file);

  if (!line.empty()) {
    int num_normals = stoi(line);

    for (int i = 0; i < num_normals; i++) {
      string str_normals = get_file_line(file);
      if (sscanf(str_normals.c_str(), "%f %f %f", &x, &y, &z) == 3) {
        normals.push_back(x);
        normals.push_back(y);
        normals.push_back(z);
      } else {
        perrorln("Invalid input: ", str_normals);
      }
    }
  }

  line = get_file_line(file);

  if (!line.empty()) {
    int num_texture_coordenates = stoi(line);

    for (int i = 0; i < num_texture_coordenates; i++) {
      string str_texture_coordenates = get_file_line(file);
      if (sscanf(str_texture_coordenates.c_str(), "%f %f", &x, &y) == 2) {
        texture_coordinates.push_back(x);
        texture_coordinates.push_back(y);
      } else {
        perrorln("Invalid input: ", str_texture_coordenates);
      }
    }
  }

  file.close();

  this->num_indexs = indexes.size();

  glGenBuffers(1, &(this->vertices));
  glBindBuffer(GL_ARRAY_BUFFER, this->vertices);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * points.size(), points.data(),
               GL_STATIC_DRAW);

  glGenBuffers(1, &(this->indices));
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indices);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indexes.size(),
               indexes.data(), GL_STATIC_DRAW);

  glGenBuffers(1, &(this->normals));
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->normals);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * normals.size(),
               normals.data(), GL_STATIC_DRAW);

  glGenBuffers(1, &(this->texture_coordinates));
  glBindBuffer(GL_ARRAY_BUFFER, this->texture_coordinates);
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * texture_coordinates.size(),
               texture_coordinates.data(), GL_STATIC_DRAW);
}

void Model3D::draw(ModelConfig *model_config) {
  // set_glcolor3f(model_config->get_color());
  glMaterialfv(GL_FRONT, GL_DIFFUSE, tupleToArray(model_config->get_diffuse()));
  glMaterialfv(GL_FRONT, GL_AMBIENT, tupleToArray(model_config->get_ambient()));
  glMaterialfv(GL_FRONT, GL_SPECULAR,
               tupleToArray(model_config->get_specular()));
  glMaterialfv(GL_FRONT, GL_EMISSION,
               tupleToArray(model_config->get_emissive()));
  glMaterialf(GL_FRONT, GL_SHININESS, model_config->get_shininess());

  glBindBuffer(GL_ARRAY_BUFFER, this->vertices);
  glVertexPointer(3, GL_FLOAT, 0, 0);

  glBindBuffer(GL_ARRAY_BUFFER, this->normals);
  glNormalPointer(GL_FLOAT, 0, 0);

  if (this->texture_coordinates) {
    glBindBuffer(GL_ARRAY_BUFFER, this->texture_coordinates);
    glTexCoordPointer(2, GL_FLOAT, 0, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
  }

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indices);

  // with fill
  glDrawElements(GL_TRIANGLES, this->num_indexs, GL_UNSIGNED_INT, NULL);
}