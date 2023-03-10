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

    void setDiffuse(int r, int g, int b){
        diffuseR = r;
        diffuseG = g;
        diffuseB = b;
    }

    void setAmbient(int r, int g, int b){
        ambientR = r;
        ambientG = g;
        ambientB = b;
    }

    void setSpecular(int r, int g, int b){
        specularR = r;
        specularG = g;
        specularB = b;
    }

    void setEmissive(int r, int g, int b){
        emissiveR = r;
        emissiveG = g;
        emissiveB = b;
    }

    void setShininess(int shininess){
        shininessValue = shininess;
    }

    string toString(){
        stringstream str;
            str << "MODEL: " << modelFilePath << "\n" <<
            "TEXTURE PATH: " << textureFilePath << "\n" <<
            "DIFFUSE: " << diffuseR << " " << diffuseG << " " << diffuseB << " " << "\n" <<
            "AMBIENT: " << ambientR << " " << ambientG << " " << ambientB << " " << "\n" <<
            "SPECULAR: " << specularR << " " << specularG << " " << specularB << " " << "\n" <<
            "EMISSIVE: " << emissiveR << " " << emissiveG<< " " << emissiveB << " " << "\n" <<
            "SHININESS: " << shininessValue << "\n";

        string ret;
        str >> ret;

        return ret;
    }
};