
#include "tinyxml2/tinyxml2.cpp"
#include "tinyxml2/tinyxml2.h"
#include <iostream>
#include <iomanip>

using namespace tinyxml2;
using namespace std;
#include "camera.cpp"
#include "model3d.cpp"
#include <math.h>

//TODO: make camera an object
/*
float posX = 10;
float posY = 10;
float posZ = 10;

float lookAtX = 0;
float lookAtY = 0;
float lookAtZ = 0;

// optional (only changes if the camera is not static)
float upX = 0;
float upY = 1;
float upZ = 0;

float fov = 60;
float near = 1;
float far = 1000;
*/

// move camera
float angleAlpha = 0;
float angleBeta = 0;
float radius = 5;

// window size
int w;
int h;

Camera *cameraObj = new Camera();

void setupCamera(XMLElement* cameraElem){
	int x, y, z;
	cameraElem = cameraElem->FirstChildElement();
	for(;cameraElem != NULL; cameraElem = cameraElem->NextSiblingElement()){
		
		string camAttribute = cameraElem->Name();

		if(camAttribute != "projection"){

			x = atoi(cameraElem->Attribute("x"));
			y = atoi(cameraElem->Attribute("y"));
			z = atoi(cameraElem->Attribute("z"));
			printf("debug x: %d, y: %d, z: %d \n", x,y,z);

			if(camAttribute == "position"){
				//setCameraPosition(x,y,z);
				cameraObj->posX = x;
				cameraObj->posY = y;
				cameraObj->posZ = z;
			}
			else if(camAttribute == "lookAt"){
				cameraObj->lookAtX = x;
				cameraObj->lookAtY = y;
				cameraObj->lookAtZ = z;

			}
			else if(camAttribute == "up"){
				cameraObj->upX = x;
				cameraObj->upY = y;
				cameraObj->upZ = z;
			}
		}
		else if(camAttribute == "projection"){
			cameraObj->fov = atof(cameraElem->Attribute("fov"));
			cameraObj->near = atof(cameraElem->Attribute("near"));
			cameraObj->far = atof(cameraElem->Attribute("far"));
			printf("debug fov: %.2f, near: %.2f, far: %.2f \n", cameraObj->fov,cameraObj->near,cameraObj->far);
		}
	}

}

void load3DModel(XMLElement* model){

	Model3D *newModel = new Model3D();

	newModel->modelFilePath = model->Attribute("file");

	for(model = model->FirstChildElement();model != NULL; model = model->NextSiblingElement()){
		
		string modelAttribute = model->Name();

		if(modelAttribute == "texture"){
			string textureFilePath = model->Attribute("file");
		}
		else if(modelAttribute == "color"){
			int R,G,B;
			XMLElement* colorElem = model->FirstChildElement();
			
			for(;colorElem != NULL; colorElem = colorElem->NextSiblingElement()){
				
				string colorAttributeName = colorElem->Name();

				if(colorAttributeName != "shininess"){
					R = atoi(colorElem->Attribute("R"));
					G = atoi(colorElem->Attribute("G"));
					B = atoi(colorElem->Attribute("B"));
					
					if(colorAttributeName == "diffuse"){
						newModel->setDiffuse(R,G,B);
					}
					else if(colorAttributeName == "ambient"){
						newModel->setDiffuse(R,G,B);
					}
					if(colorAttributeName == "specular"){
						newModel->setAmbient(R,G,B);
					}
					if(colorAttributeName == "emissive"){
						newModel->setEmissive(R,G,B);
					}
				}
				else if(colorAttributeName == "shininess"){
					int value = atoi(colorElem->Attribute("value"));
					newModel->setShininess(value);
				}
			}
		}
	}
}

void loadModels(XMLElement* modelsElem){
	
	for(;modelsElem != NULL; modelsElem = modelsElem->NextSiblingElement()){
		
		string modelsAttribute = modelsElem->Name();

		if(modelsAttribute == "model"){
			cout << "loading model\n";
			load3DModel(modelsElem);
		}
		else{
			cout << "invalid attribute: " << modelsAttribute << "\n";
		}
	}


}

void setupWorld(XMLElement* worldElement){
	
	// obtenho o primeiro elemento (no caso <window>)
	XMLElement *e = worldElement->FirstChildElement();

	// percorrer os "nodos" do ficheiro XML
    while (e != NULL){
	
		// para cada nodo tiro o seu valor (<camera>, <position>, ...)
        string param = e->Value();

		if(param == "window"){
			int width = atoi(e->Attribute("width"));
			int height = atoi(e->Attribute("height"));

			if (width > 0 && height > 0){
				w = width; h = height;
				//glutReshapeWindow(width,height);
			}
		}
		else if (param == "camera"){
			
			XMLElement *camera = e->FirstChildElement();
			setupCamera(camera);
			cout << "finished camera setup\n";
			
		}
		else if (param == "lights"){
			// percorrer luzes
		}
		else if (param == "group"){
			
			XMLElement *item = e->FirstChildElement();
			
			while(item != NULL){
        		string groupElemName = item->Value();
				
				if(groupElemName == "transform"){
					//loadTransformations(item->FirstChildElement());
					printf("[transform] only required from phase 2\n");
				}
				else if(groupElemName == "models"){
					loadModels(item->FirstChildElement());
				}
				else{ break; }

				item = item->NextSiblingElement();
			}

		}
		e = e->NextSiblingElement();
	}

}

int main(int argc, char **argv) {

//  Reading XML config file and setting up

    XMLDocument doc;
    const char * path = "xml_teste.xml";
    //const char * path = argv[1];

    bool loadOk = doc.LoadFile(path);
    XMLElement * worldElement = doc.RootElement();
    
	if (loadOk == XML_SUCCESS) {
        setupWorld(worldElement);
    } else {
        cout << "Erro ao ler ficheiro de configuração XML->" << path;
    }
	
	return 1;
}
