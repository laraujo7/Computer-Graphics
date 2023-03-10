#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "includes.h"
using namespace std;

class Model3D{
private:
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

    GLuint vertices, indices, verticeCount;
    unsigned int indexCount;

  public:
    Model3D(string modelFilePath) {
        this->modelFilePath = modelFilePath;

        read3dFile(modelFilePath);
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

    void insertPoint(vector <float> &points, int x, int y, int z){
        points.push_back(x);
        points.push_back(y);
        points.push_back(z);

    }

    void insertIndex(vector <unsigned int> &points, int x, int y, int z){
        points.push_back(x);
        points.push_back(y);
        points.push_back(z);

    }

    void cylinderPoints(float radius, float height, int slices, vector <float> &points){
        float interval = (2*M_PI) / slices;
        float h = 0;

        // base point
        insertPoint(points, 0, 0, 0);
        
        // top point
        insertPoint(points, 0, height, 0);
        
        // side points
        for(int i=0; i < 2; i++){
            
            for(int j=0; j<slices; j++){
                float angle = j * interval;
                insertPoint(points, radius*sin(angle), h, radius*cos(angle));
                
            }

            h = height;
	    }
    }

    void indexPoints(int slices, vector <unsigned int> &indexes){
	for(int i = 0; i < slices; i++){
		// base points
		insertIndex(indexes, 0, 2+i, 2+i+1);

		// side points
		insertIndex(indexes, 2+i, 2+i+1,2+slices+i+1);
		insertIndex(indexes, 2+i, 2+slices+i+1, 2+slices+i);

		// top points
		insertIndex(indexes, 1, 2+slices+i, 2+slices+i+1);
	    }
    }

    void writeCylinder(float radius, float height, int slices) {
	
        vector <unsigned int> indexes;
        vector <float> coords;

        cylinderPoints(radius, height, slices, coords);
        indexPoints(slices, indexes);

        verticeCount = coords.size() / 3;
        indexCount = indexes.size();
        
        glGenBuffers(1, &vertices);
        glBindBuffer(GL_ARRAY_BUFFER, vertices);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float)*coords.size(), coords.data(), GL_STATIC_DRAW);

        glGenBuffers(1, &indices);
        glBindBuffer(GL_ARRAY_BUFFER, indices);
        glBufferData(GL_ARRAY_BUFFER, sizeof(unsigned int)*indexes.size(), indexes.data(), GL_STATIC_DRAW);

    }
    

    void read3dFile(string filePath){
        cout << "esferovite\n";
        ifstream file(filePath);
        if (file.is_open()) {
            string nomeModelo;
            getline(file, nomeModelo);
            cout << nomeModelo << endl;

            string numPontosStr;
            getline(file, numPontosStr);
            int numPontos = stoi(numPontosStr);
            cout << numPontosStr << endl;

            string coords;
            float x,y,z;
            
            for(int i = 0; i < numPontos; i++){
                getline(file, coords);
                if (std::sscanf(coords.c_str(), "%f %f %f", &x, &y, &z) == 3) {
                    std::cout << "Parsed: " << x << ", " << y << ", " << z << "\n";
                    } else {
                        std::cerr << "Invalid input: " << coords << "\n";
                }
            }

            string numTriangulosStr;
            getline(file, numTriangulosStr);
            int numTriangulos = stoi(numTriangulosStr);
            cout << numTriangulosStr << endl;

            string indexes;
            int i1,i2,i3;

            for(int i = 0; i < numTriangulos; i++){
                getline(file, indexes);
                if (std::sscanf(indexes.c_str(), "%d %d %d", &i1, &i2, &i3) == 3) {
                std::cout << "Parsed: " << i1 << ", " << i2 << ", " << i3 << "\n";
                } else {
                    std::cerr << "Invalid input: " << indexes << "\n";
                }
            }

            
            
            file.close();
        }
    }

};
/*
    void read3dFile(string filePath){
        cout << "esferovite\n";
        ifstream file(filePath);
        if (file.is_open()) {
            string nomeModelo;
            getline(file, nomeModelo);
            cout << nomeModelo << endl;

            string numPontosStr;
            getline(file, numPontosStr);
            int numPontos = stoi(numPontosStr);
            cout << numPontosStr << endl;

            string coords;
            float x,y,z;
            
            for(int i = 0; i < numPontos; i++){
                getline(file, coords);
                if (std::sscanf(coords.c_str(), "%f %f %f", &x, &y, &z) == 3) {
                    std::cout << "Parsed: " << x << ", " << y << ", " << z << "\n";
                    } else {
                        std::cerr << "Invalid input: " << coords << "\n";
                }
            }

            string numTriangulosStr;
            getline(file, numTriangulosStr);
            int numTriangulos = stoi(numTriangulosStr);
            cout << numTriangulosStr << endl;

            string indexes;
            int i1,i2,i3;

            for(int i = 0; i < numTriangulos; i++){
                getline(file, indexes);
                if (std::sscanf(indexes.c_str(), "%d %d %d", &i1, &i2, &i3) == 3) {
                std::cout << "Parsed: " << i1 << ", " << i2 << ", " << i3 << "\n";
                } else {
                    std::cerr << "Invalid input: " << indexes << "\n";
                }
            }

            
            
            file.close();
        }
    }

int main(int argc, char **argv) {
    read3dFile(argv[1]);

    return 1;
}
*/