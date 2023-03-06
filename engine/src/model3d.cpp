#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "includes.h"
using namespace std;

#include <bits/stdc++.h>

class Model3D{
private:
    string modelFilePath;
    string textureFilePath;

    // default color attributes
    tuple<int, int, int> diffuse = make_tuple(50, 50, 50);
    tuple<int, int, int> ambient = make_tuple(200, 200, 200);
    tuple<int, int, int> specular = make_tuple(0, 0, 0);
    tuple<int, int, int> emissive = make_tuple(0, 0, 0);

    GLuint vertices, indices, verticeCount;
    unsigned int indexCount;

    vector <unsigned int> indexes;
    vector <float> coords;

    int shininess = 0;
  public:
    Model3D() {}

    Model3D(Model3D model) {
        this->modelFilePath = model->modelFilePath;
        this->textureFilePath = model->textureFilePath;
        this->diffuse = model->diffuse;
        this->ambient = model->ambient;
        this->specular = model->specular;
        this->emissive = model->emissive;
        this->shininess = model->shininess;
    }

    Model3D(string modelFilePath, string textureFilePath, tuple<int, int, int> diffuse, tuple<int, int, int> ambient, tuple<int, int, int> specular, tuple<int, int, int> emissive, int shininess) {
        this->modelFilePath = modelFilePath;
        this->textureFilePath = textureFilePath;
        this->diffuse = diffuse;
        this->ambient = ambient;
        this->specular = specular;
        this->emissive = emissive;
        this->shininess = shininess;
    }

    Model3D(string modelFilePath) {
        this->modelFilePath = modelFilePath;
        // read3dFile(modelFilePath);
    }

    string getModelFilePath(){
        return this->modelFilePath;
    }

    string getTextureFilePath(){
        return this->textureFilePath;
    }

    tuple<int, int, int> getDiffuse(){
        return this->diffuse;
    }

    tuple<int, int, int> getAmbient(){
        return this->ambient;
    }

    tuple<int, int, int> getSpecular(){
        return this->specular;
    }

    tuple<int, int, int> getEmissive(){
        return this->emissive;
    }

    int getShininess(){
        return this->shininess;
    }

    void setModelFilePath(string path){
        this->modelFilePath = path;
    }

    void setTextureFilePath(string path){
        this->textureFilePath = path;
    }

    void setDiffuse(tuple<int, int, int> diffuse){
        this->diffuse = diffuse;
    }

    void setDiffuse(int r, int g, int b){
        this->diffuse = make_tuple(r, g, b);
    }

    void setAmbient(tuple<int, int, int> ambient){
        this->ambient = ambient;
    }

    void setAmbient(int r, int g, int b){
        this->ambient = make_tuple(r, g, b);
    }

    void setSpecular(tuple<int, int, int> specular){
        this->specular = specular;
    }

    void setSpecular(int r, int g, int b){
        this->specular = make_tuple(r, g, b);
    }

    void setEmissive(tuple<int, int, int> emissive){
        this->emissive = emissive;
    }

    void setEmissive(int r, int g, int b){
        this->emissive = make_tuple(r, g, b);
    }

    void setShininess(int shininess){
        this->shininess = shininess;
    }

    string toString(){
        return
            "MODEL: " + this->modelFilePath + "\n" +
            "TEXTURE: " + this->textureFilePath + "\n" +
            "DIFFUSE: " + to_string(get<0>(this->diffuse)) + " " + to_string(get<1>(this->diffuse)) + to_string(get<2>(this->diffuse)) + "\n" +
            "AMBIENT: " + to_string(get<0>(this->ambient)) + " " + to_string(get<1>(this->ambient)) + to_string(get<2>(this->ambient)) + "\n" +
            "SPECULAR: " + to_string(get<0>(this->specular)) + " " + to_string(get<1>(this->specular)) + to_string(get<2>(this->specular)) + "\n" +
            "EMISSIVE: " + to_string(get<0>(this->emissive)) + " " + to_string(get<1>(this->emissive)) + to_string(get<2>(this->emissive)) + "\n" +
            "SHININESS: " + to_string(this->shininess);
    }

    // void insertPoint(vector <float> &points, int x, int y, int z){
    //     points.push_back(x);
    //     points.push_back(y);
    //     points.push_back(z);

    // }

    // void insertIndex(vector <unsigned int> &points, int x, int y, int z){
    //     points.push_back(x);
    //     points.push_back(y);
    //     points.push_back(z);

    // }

    // void cylinderPoints(float radius, float height, int slices, vector <float> &points){
    //     float interval = (2*M_PI) / slices;
    //     float h = 0;

    //     // base point
    //     insertPoint(points, 0, 0, 0);

    //     // top point
    //     insertPoint(points, 0, height, 0);

    //     // side points
    //     for(int i=0; i < 2; i++){
    //         for(int j=0; j<slices; j++){
    //             float angle = j * interval;
    //             insertPoint(points, radius*sin(angle), h, radius*cos(angle));
    //         }

    //         h = height;
	//     }
    // }

    // void indexPoints(int slices, vector <unsigned int> &indexes){
	// for(int i = 0; i < slices; i++){
	// 	// base points
	// 	insertIndex(indexes, 0, 2+i, 2+i+1);

	// 	// side points
	// 	insertIndex(indexes, 2+i, 2+i+1,2+slices+i+1);
	// 	insertIndex(indexes, 2+i, 2+slices+i+1, 2+slices+i);

	// 	// top points
	// 	insertIndex(indexes, 1, 2+slices+i, 2+slices+i+1);
	//     }
    // }

    // void writeCylinder(float radius, float height, int slices) {
	
    //     vector <unsigned int> indexes;
    //     vector <float> coords;

    //     cylinderPoints(radius, height, slices, coords);
    //     indexPoints(slices, indexes);

    //     verticeCount = coords.size() / 3;
    //     indexCount = indexes.size();
        
    //     glGenBuffers(1, &vertices);
    //     glBindBuffer(GL_ARRAY_BUFFER, vertices);
    //     glBufferData(GL_ARRAY_BUFFER, sizeof(float)*coords.size(), coords.data(), GL_STATIC_DRAW);

    //     glGenBuffers(1, &indices);
    //     glBindBuffer(GL_ARRAY_BUFFER, indices);
    //     glBufferData(GL_ARRAY_BUFFER, sizeof(unsigned int)*indexes.size(), indexes.data(), GL_STATIC_DRAW);

    // }

    string getLine(ifstream file) {
        println(getline(file));
    }

    void read3dFile(string filePath){

        ifstream file(filePath);
        if (file.is_open()) {
            string newModel;
            getline(file, newModel);
            println(newModel);

            // string numPontosStr;
            getLine(file);
            // int numPontos = stoi(numPontosStr);
            // cout << numPontosStr << endl;

            string coordsStr;
            float x,y,z;

            for(int i = 0; i < numPontos; i++){
                getline(file, coordsStr);
                if (sscanf(coordsStr.c_str(), "%f %f %f", &x, &y, &z) == 3) {
                    //cout << "Parsed: " << x << ", " << y << ", " << z << "\n";
                    insertPoint(coords, x, y, z);
                    } else {
                        cerr << "Invalid input: " << coordsStr << "\n";
                }
            }

            string numTriangulosStr;
            getline(file, numTriangulosStr);
            int numTriangulos = stoi(numTriangulosStr);
            cout << numTriangulosStr << endl;

            string indexesStr;
            int i1,i2,i3;

            for(int i = 0; i < numTriangulos; i++){
                getline(file, indexesStr);
                if (sscanf(indexesStr.c_str(), "%d %d %d", &i1, &i2, &i3) == 3) {
                //cout << "Parsed: " << i1 << ", " << i2 << ", " << i3 << "\n";
                    insertIndex(indexes, i1, i2, i3);
                } else {
                    cerr << "Invalid input: " << indexesStr << "\n";
                }
            }
            file.close();

            verticeCount = coords.size() / 3;
            indexCount = indexes.size();

            glGenBuffers(1, &vertices);
            glBindBuffer(GL_ARRAY_BUFFER, vertices);
            glBufferData(GL_ARRAY_BUFFER, sizeof(float)*coords.size(), coords.data(), GL_STATIC_DRAW);

            glGenBuffers(1, &indices);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*indexes.size(), indexes.data(), GL_STATIC_DRAW);


        }
    }

    void draw(){

        glBindBuffer(GL_ARRAY_BUFFER,vertices);
        glVertexPointer(3,GL_FLOAT,0,0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices);

        // with fill
        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, NULL);

        // wireframe
        //glDrawElements(GL_LINES, indexCount, GL_UNSIGNED_INT, NULL);

    }
};