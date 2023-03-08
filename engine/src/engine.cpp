#include <GL/freeglut_std.h>
#include <GL/gl.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#include "tinyxml2/tinyxml2.cpp"
#include "tinyxml2/tinyxml2.h"
#include <iostream>
#include <iomanip>

using namespace tinyxml2;
using namespace std;

#include <math.h>

//TODO: make camera an object

float camX = 1.0;
float camY = 1.0;
float camZ = 1.0;
float angle = 0;

int w;
int h;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}


void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(5.0,5.0,5.0, 
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

	glBegin(GL_LINES);
		// X axis in red
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-100.0f, 0.0f, 0.0f);
		glVertex3f( 100.0f, 0.0f, 0.0f);
		// Y Axis in Green
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, -100.0f, 0.0f);
		glVertex3f(0.0f, 100.0f, 0.0f);
		// Z Axis in Blue
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, -100.0f);
		glVertex3f(0.0f, 0.0f, 100.0f);

	glEnd();

	glRotatef(angle, camX, camY, camZ);

	glutWireTeapot(1);

	

// put the geometric transformations here


// put pyramid drawing instructions here


	// End of frame
	glutSwapBuffers();
}



// write function to process keyboard events
void keyboardCtrl(unsigned char key, int x, int y){

	switch(key){
		case 'd': // direita
			camX -= 50.0;
			break;
		case 'a': // esquerda
			camX += 50.0;
			break;
		case 'w': // cima
			camZ += 50.0;
			break;
		case 's': // baixo
			camZ -= 50.0;
			break;
	}

	glutPostRedisplay();
}

void mouseCtrl(int button, int state, int x, int y){
	if(state == GLUT_DOWN){
		angle += (x + y);
		camX = x;
		camY = y;
	}
	glutPostRedisplay();
}

void setupCamera(XMLElement* camera){
	int x, y, z;

	for(; camera != NULL; camera = camera->NextSiblingElement()){
		
		string camAttribute = camera->Name();
		
		if(camAttribute != "projection"){
			x = atoi(camera->Attribute("x"));
			y = atoi(camera->Attribute("y"));
			z = atoi(camera->Attribute("z"));
			printf("debug x: %d, y: %d, z: %d \n", x,y,z);

			if(camAttribute == "position"){
				//setCameraPosition(x,y,z);
				camX = x;
				camY = y;
				camZ = z;
			}
			else if(camAttribute == "lookAt"){
				//setCameraLookAt(x,y,z);
			}
			else if(camAttribute == "up"){
				//setCameraUp(x,y,z);
			}
		}
		else {
			int fov = atoi(camera->Attribute("fov"));
			int near = atoi(camera->Attribute("near"));
			int far = atoi(camera->Attribute("far"));
			printf("debug fov: %d, near: %d, far: %d \n", fov,near,far);
			float ratio = w * 1.0 / h;
			gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

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
				glutReshapeWindow(width,height);
			}
		}
		else if (param == "camera"){
			
			XMLElement *camera = e->FirstChildElement();
			setupCamera(camera);
			
		}
		else if (param == "lights"){
			// percorrer luzes
		}
		else if (param == "group"){
			// transform
			// models

		}
		e = e->NextSiblingElement();
	}


}
int main(int argc, char **argv) {

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("Teste");
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	
// put here the registration of the keyboard callbacks
	glutKeyboardFunc(keyboardCtrl);
	glutMouseFunc(mouseCtrl);


//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

//  Reading XML config file and setting up

    XMLDocument doc;
    const char * path = "xml_teste.xml";
    bool loadOk = doc.LoadFile(path);
    XMLElement * worldElement = doc.RootElement();
    
	if (loadOk == XML_SUCCESS) {
        setupWorld(worldElement);
    } else {
        cout << "Erro ao ler ficheiro de configuração XML->" << path;
    }
	
// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}
