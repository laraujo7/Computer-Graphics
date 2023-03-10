#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Model3D{

  public:

    string modelFilePath;
    string textureFilePath;

    // default color attributes
    int diffuseR= 200;
    int diffuseG=200;
    int diffuseB=200;

    int ambientR=50;
    int ambientG=50;
    int ambientB=50;

    int specularR=0;
    int specularG=0;
    int specularB=0;
    
    int emissiveR=0;
    int emissiveG=0;
    int emissiveB=0;
    
    int shininessValue=0;

    Model3D(string modelFilePath) {
        this->modelFilePath = modelFilePath;
    }

    void setTextureFilePath(string path){
        this->textureFilePath = path;
    }

    void setDiffuse(int r, int g, int b){
        this->diffuseR = r;
        this->diffuseG = g;
        this->diffuseB = b;
    }

    void setAmbient(int r, int g, int b){
        this->ambientR = r;
        this->ambientG = g;
        this->ambientB = b;
    }

    void setSpecular(int r, int g, int b){
        this->specularR = r;
        this->specularG = g;
        this->specularB = b;
    }

    void setEmissive(int r, int g, int b){
        this->emissiveR = r;
        this->emissiveG = g;
        this->emissiveB = b;
    }

    void setShininess(int shininess){
        this->shininessValue = shininess;
    }

    string toString(){
        stringstream str;
            str << "MODEL: " << this->modelFilePath << "\n" <<
            "DIFFUSE: " << this->diffuseR << " " << this->diffuseG << " " << this->diffuseB << " " << "\n" <<
            "AMBIENT: " << this->ambientR << " " << this->ambientG << " " << this->ambientB << " " << "\n" <<
            "SPECULAR: " << this->specularR << " " << this->specularG << " " << this->specularB << " " << "\n" <<
            "EMISSIVE: " << this->emissiveR << " " << this->emissiveG<< " " << this->emissiveB << " " << "\n" <<
            "SHININESS: " << this->shininessValue << "\n";

        string ret;
        str >> ret;

        return ret;
    }
};