#ifndef CAMERA_H
#define CAMERA_H

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

class Camera {
private:
  tuple<float, float, float> position;
  tuple<float, float, float> look_at;
  tuple<float, float, float> up;
  tuple<float, float, float> projection;

  float radius;
  float alpha;
  float beta;

public:
  Camera();

  Camera(float radius, float alpha, float beta);

  Camera(float raio);

  void get_position(float *arr);

  void get_position(vector<float> &arr);

  tuple<float, float, float> get_position();

  void get_look_at(float *arr);

  void get_look_at(vector<float> &arr);

  tuple<float, float, float> get_look_at();

  void get_up(float *arr);

  void get_up(vector<float> &arr);

  tuple<float, float, float> get_up();

  void get_projection(float *arr);

  void get_projection(vector<float> &arr);

  tuple<float, float, float> get_projection();

  void set_position(float x, float y, float z);

  void set_position(float arr[3]);

  void set_position(vector<float> &arr);

  void set_look_at(float x, float y, float z);

  void set_look_at(float arr[3]);

  void set_look_at(vector<float> &arr);

  void set_up(float x, float y, float z);

  void set_up(float arr[3]);

  void set_up(vector<float> &arr);

  void set_projection(float fov, float near, float far);

  void set_projection(float arr[3]);

  void set_projection(vector<float> &arr);

  // coordinates from radius, alpha and beta into array
  tuple<float, float, float> get_camera_position(float radius, float alpha,
                                                 float beta);

  string camera_to_string();

  string camera_position_to_string();

  string camera_look_at_to_string();

  string camera_projection_to_string();

  string camera_up_to_string();
};
#endif