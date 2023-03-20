#include "camera.hpp"

Camera::Camera() {}

Camera::Camera(float radius, float alpha, float beta) {
  this->radius = radius;
  this->alpha = alpha;
  this->beta = beta;
  this->position = get_camera_position(radius, alpha, beta);
}

Camera::Camera(float raio) {
  this->radius = raio;
  this->alpha = 0;
  this->beta = M_PI / 4;
  // uses default alpha and beta
}

void Camera::get_position(float *arr) {
  arr[0] = get<0>(this->position);
  arr[1] = get<1>(this->position);
  arr[2] = get<2>(this->position);
}

void Camera::get_position(vector<float> &arr) {
  arr[0] = get<0>(this->position);
  arr[1] = get<1>(this->position);
  arr[2] = get<2>(this->position);
}

tuple<float, float, float> Camera::get_position() {
  return make_tuple(get<0>(this->position), get<1>(this->position),
                    get<2>(this->position));
}

void Camera::get_look_at(float *arr) {
  arr[0] = get<0>(this->look_at);
  arr[1] = get<1>(this->look_at);
  arr[2] = get<2>(this->look_at);
}

void Camera::get_look_at(vector<float> &arr) {
  arr[0] = get<0>(this->look_at);
  arr[1] = get<1>(this->look_at);
  arr[2] = get<2>(this->look_at);
}

tuple<float, float, float> Camera::get_look_at() {
  return make_tuple(get<0>(this->look_at), get<1>(this->look_at),
                    get<2>(this->look_at));
}

void Camera::get_up(float *arr) {
  arr[0] = get<0>(this->up);
  arr[1] = get<1>(this->up);
  arr[2] = get<2>(this->up);
}

void Camera::get_up(vector<float> &arr) {
  arr[0] = get<0>(this->up);
  arr[1] = get<1>(this->up);
  arr[2] = get<2>(this->up);
}

tuple<float, float, float> Camera::get_up() {
  return make_tuple(get<0>(this->up), get<1>(this->up), get<2>(this->up));
}

void Camera::get_projection(float *arr) {
  arr[0] = get<0>(this->projection);
  arr[1] = get<1>(this->projection);
  arr[2] = get<2>(this->projection);
}

void Camera::get_projection(vector<float> &arr) {
  arr[0] = get<0>(this->projection);
  arr[1] = get<1>(this->projection);
  arr[2] = get<2>(this->projection);
}

tuple<float, float, float> Camera::get_projection() {
  return make_tuple(get<0>(this->projection), get<1>(this->projection),
                    get<2>(this->projection));
}

void Camera::set_position(float x, float y, float z) {
  this->position = make_tuple(x, y, z);
}

void Camera::set_position(float arr[3]) {
  this->position = make_tuple(arr[0], arr[1], arr[2]);
}

void Camera::set_position(vector<float> &arr) {
  this->position = make_tuple(arr[0], arr[1], arr[2]);
}

void Camera::set_look_at(float x, float y, float z) {
  this->look_at = make_tuple(x, y, z);
}

void Camera::set_look_at(float arr[3]) {
  this->look_at = make_tuple(arr[0], arr[1], arr[2]);
}

void Camera::set_look_at(vector<float> &arr) {
  this->look_at = make_tuple(arr[0], arr[1], arr[2]);
}

void Camera::set_up(float x, float y, float z) {
  this->up = make_tuple(x, y, z);
}

void Camera::set_up(float arr[3]) {
  this->up = make_tuple(arr[0], arr[1], arr[2]);
}

void Camera::set_up(vector<float> &arr) {
  this->up = make_tuple(arr[0], arr[1], arr[2]);
}

void Camera::set_projection(float fov, float near, float far) {
  this->projection = make_tuple(fov, near, far);
}

void Camera::set_projection(float arr[3]) {
  this->projection = make_tuple(arr[0], arr[1], arr[2]);
}

void Camera::set_projection(vector<float> &arr) {
  this->projection = make_tuple(arr[0], arr[1], arr[2]);
}

// coordinates from radius, alpha and beta into array
tuple<float, float, float>
Camera::get_camera_position(float radius, float alpha, float beta) {
  float x = radius * cos(beta) * sin(alpha);
  float y = radius * sin(beta);
  float z = radius * cos(beta) * cos(alpha);

  return make_tuple(x, y, z);
}