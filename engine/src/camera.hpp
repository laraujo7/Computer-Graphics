#ifndef CAMERA_H
#define CAMERA_H

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

class Camera {
private:
    tuple<float, float, float> position;
    tuple<float, float, float> lookAt;

    // float posX;
    // float posY;
    // float posZ;

    // float lookAtX;
    // float lookAtY;
    // float lookAtZ;

    float radius;
    float alpha;
    float beta;

public:
    Camera() {}

    Camera(float radius, float alpha, float beta) {
        this->radius = radius;
        this->alpha = alpha;
        this->beta = beta;
        float pos[3];
        this->pos(pos);
        this->posX = pos[0];
        this->posY = pos[1];
        this->posZ = pos[2];
    }

    Camera(float raio) {
        this->radius = raio;
        this->alpha = 0;
        this->beta = M_PI/4;
        // uses default alpha and beta
    }

    void getPosition(float *arr){
        for(int i=0; i < 3; i++){
            arr[i] = get<i>(this->position);
        }
    }

    void getPosition(vector<float> &arr){
        for(int i=0; i < 3; i++){
            arr.push_back(get<i>(this->position));
        }
    }

    vector<float> getPosition(){
        vector<float> arr;
        for(int i=0; i < 3; i++){
            arr.push_back(get<i>(this->position));
        }

        return arr;
    }

    float* getPosition(){
        return [get<0>(this->position), get<1>(this->position), get<2>(this->position)];
    }

    void getLookAt(float *arr){
        for(int i=0; i < 3; i++){
            arr[i] = get<i>(this->lookAt);
        }
    }

    void getLookAt(vector<float> &arr){
        for(int i=0; i < 3; i++){
            arr.push_back(get<i>(this->lookAt));
        }
    }

    vector<float> getLookAt(){
        return make_tuple(get<0>(this->lookAt), get<1>(this->lookAt), get<2>(this->lookAt))
    }

    float* getLookAt(){
        float *arr;
        for(int i=0; i < 3; i++){
            arr[i] = get<i>(this->lookAt);
        }
        return arr;
    }

    void getLookAt(float arr[3]){
        arr[0] = this->lookAtX;
        arr[1] = this->lookAtY;
        arr[2] = this->lookAtZ;
    }

    void setPosition(float arr[3]){
        this->posX = arr[0];
        this->posY = arr[1];
        this->posZ = arr[2];
    }

    void setLookAt(float arr[3]){
        this->lookAtX = arr[0];
        this->lookAtY = arr[1];
        this->lookAtZ = arr[2];
    }

    // coordinates from radius, alpha and beta into array
    void pos(float arr[3]) {
        arr[0] = radius * cos(beta) * sin(alpha);
        arr[1] = radius * sin(beta);
        arr[2] = radius * cos(beta) * cos(alpha);
    }

    void lookAt(float arr[3]) {
            arr[0] = arr[1] = arr[2] = 0.0f;
    }
};
#endif