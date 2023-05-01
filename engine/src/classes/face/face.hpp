#ifndef FACE_H
#define FACE_H

#include <GL/glut.h>
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Face {
private:
  vector<int> vertice_indeces;
  vector<int> texture_indeces;
  int normal;

public:
  Face();

  Face(const Face &face);

  Face(vector<int> vertice_indeces, vector<int> texture_indeces, int normal);

  vector<int> get_vertice_indeces();

  vector<int> get_texture_indeces();

  int get_normal();

  void set_vertice_indeces(vector<int> vertice_indeces);

  void set_texture_indeces(vector<int> texture_indeces);

  void set_normal(int normal);

  void add_vertice_index(int vertice_index);

  void add_texture_index(int texture_index);
};
#endif