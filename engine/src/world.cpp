#include "includes.h"
#include "camera.hpp"
#include "model3d.cpp"
#include "../lib/tinyxml2/tinyxml2.h"
using namespace tinyxml2;

class World{
	private:

	// window
	int w;
	int h;

	Camera *camera = new Camera();

	public:

	World(){}

	void loadXML(char* filePath){
		XMLDocument doc;
		//const char * path = filePath;

		bool loadOk = doc.LoadFile(filePath);
		XMLElement * worldElement = doc.RootElement();

		if (loadOk == XML_SUCCESS) {
			setupWorld(worldElement);
		} else {
			cout << "Erro ao ler ficheiro de configuração XML->" << (string)filePath;
		}
	}


	void setupCamera(XMLElement* cameraElem){

		float x, y, z;

		for(;cameraElem != NULL; cameraElem = cameraElem->NextSiblingElement()){
			string camAttribute = cameraElem->Name();

			x = stof(cameraElem->Attribute("x"));
			y = stof(cameraElem->Attribute("y"));
			z = stof(cameraElem->Attribute("z"));
			float arr[3] = {x,y,z};

			if(camAttribute == "position"){
				camera->setPosition(arr);

			}
			else if(camAttribute == "lookAt"){
				camera->setLookAt(arr);
			}
			else{
				break;
			}
		}

	}

	void load3DModel(XMLElement* modelElem, Model3D *newModel){

		for(XMLElement *model = modelElem->FirstChildElement(); model != NULL; model = model->NextSiblingElement()){

			string modelAttribute = model->Name();

			if(modelAttribute == "texture"){
				newModel->setTextureFilePath(model->Attribute("file"));
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
						if(colorAttributeName == "ambient"){
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

	void getCamPosition(float arr[3]){
		float aux[3];
		camera->getPosition(aux);
		arr[0] = aux[0];
		arr[1] = aux[1];
		arr[2] = aux[2];
	}

	void getCamLookAt(float arr[3]){
		float aux[3];
		camera->getLookAt(aux);
		arr[0] = aux[0];
		arr[1] = aux[1];
		arr[2] = aux[2];
	}

	void loadModels(XMLElement* modelsElem){
		for(XMLElement *model = modelsElem->FirstChildElement(); model != NULL; model = model->NextSiblingElement()){
			//cout << model->Attribute("file") << endl;
			Model3D *newModel = new Model3D(model->Attribute("file"));

			load3DModel(model->FirstChildElement(), newModel);
			

		}
		/*
		for(;modelsElem != NULL; modelsElem = modelsElem->NextSiblingElement()){
			
			string modelsAttribute = modelsElem->Name();
			cout << modelsAttribute;

			if(modelsAttribute == "model"){
				load3DModel(modelsElem);
			}
			else{
				cout << "invalid attribute: " << modelsAttribute << "\n";
			}
		}
		*/
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
					glutReshapeWindow(width,height);
				}
			}
			else if (param == "camera"){
				setupCamera(e->FirstChildElement());
			}
			else if (param == "lights"){
				// percorrer luzes
			}
			else if (param == "group"){
				
				
				for(XMLElement *item = e->FirstChildElement(); item != NULL; item = item->NextSiblingElement()){
				//while(item != NULL){
					string groupElemName = item->Value();
					cout << groupElemName << endl;
					
					if(groupElemName == "transform"){
						//loadTransformations(item->FirstChildElement());
						cout << "[transform] only required from phase 2\n";
					}
					else if(groupElemName == "models"){
						loadModels(item);
					}
				}

			}
			e = e->NextSiblingElement();
		}

	}

};