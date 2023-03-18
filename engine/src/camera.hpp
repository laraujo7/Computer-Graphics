#ifndef CAMERA_H
#define CAMERA_H

#include "includes.h"

class Camera {
private:
    float posX;
    float posY;
    float posZ;

    float lookAtX;
    float lookAtY;
    float lookAtZ;

    float radius;
    float alpha;
    float beta;

public:
    Camera() {}

    Camera(float raio, float alpha, float beta) {
        this->radius = raio;
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

    void getPosition(float arr[3]){
        arr[0] = this->posX;
        arr[1] = this->posY;
        arr[2] = this->posZ;
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