#include "modelObj.hpp"

ModelObj::ModelObj() {}

ModelObj::ModelObj(const ModelObj &model) {
  this->model_file_path = model.model_file_path;
  read_file(model.model_file_path);
}

ModelObj::ModelObj(string model_file_path) {
  this->model_file_path = model_file_path;
  read_file(model_file_path);
}

string ModelObj::get_model_file_path() { return this->model_file_path; }

void ModelObj::set_model_file_path(string path) {
  this->model_file_path = path;
}

void parse_face(string line, vector<Face> &faces) {
  vector<string> strs_face = tokenize(line, ' ');
  strs_face.erase(strs_face.begin());

  if (!strs_face.empty()) {
    Face face = Face();
    for (string str_face : strs_face) {
      vector<string> str_value = tokenize(str_face, '/');

      face.add_vertice_index(stoi(str_value[0]) - 1);

      if (str_value.size() > 1 && str_value[1].compare(""))
        face.add_texture_index(stoi(str_value[1]) - 1);
      if (str_value.size() > 2)
        face.set_normal(stoi(str_value[2]));
    }
    faces.push_back(face);
  }
}

void ModelObj::read_file(string file_path) {
  string DEFAULT_FILE_PATH = "models/";
  ifstream file(DEFAULT_FILE_PATH + file_path);

  if (!file.is_open()) {
    println("Couldn't open the provided file");
    return;
  }

  float x, y, z;
  int i1, i2, i3, i4;
  vector<float *> vertices;
  vector<Face> faces;

  string model_name = get_file_line(file);

  while (!file.eof()) {
    string line = get_file_line(file);
    vector<string> tags = tokenize(line, ' ');

    if (!tags.empty()) {
      switch (get_obj_tag(tags[0])) {
      case ObjTags::VERTEX: {
        sscanf(line.c_str(), "v %f %f %f", &x, &y, &z);
        vertices.push_back(new float[3]{x, y, z});
      } break;

      case ObjTags::VERTEX_TEXTURE:
        sscanf(line.c_str(), "vt %f %f %f", &x, &y);
        break;

      case ObjTags::VERTEX_NORMAL:
        sscanf(line.c_str(), "vn %f %f %f", &x, &y, &z);
        break;

      case ObjTags::FACE: {
        parse_face(line, faces);
      } break;

      case ObjTags::MTLLIB: {
        char *str;
        sscanf(line.c_str(), "mtllib %s", &str);
      } break;

      case ObjTags::USEMTL: {
        char *str;
        sscanf(line.c_str(), "usemtl %s", &str);
      } break;

      case ObjTags::NONE:
      default:
        break;
      }
    }
  }

  file.close();

  this->list = glGenLists(1);
  glNewList(list, GL_COMPILE);
  for (Face face : faces) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < face.get_vertice_indeces().size(); i++) {
      glVertex3fv(vertices[face.get_vertice_indeces()[i]]);
    }
    glEnd();
  }
  glEndList();
}

void ModelObj::draw(ModelConfig *model_config) {
  set_glcolor3f(model_config->get_color());
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glCallList(this->list);
}