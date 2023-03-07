/*
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
*/

#include "tinyxml2/tinyxml2.cpp"
#include <iostream>
#include <iomanip>

using namespace tinyxml2;
using namespace std;

#include <math.h>

float camX = 1.0;
float camY = 1.0;
float camZ = 1.0;
float angle = 0;

/*
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


// put axis drawing in here
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
	glEnd();

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
			camX -= 1.0;
			break;
		case 'a': // esquerda
			camX += 1.0;
			break;
		case 'w': // cima
			camY += 1.0;
			break;
		case 's': // baixo
			camY -= 1.0;
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
*/

int main(int argc, char **argv) {

    XMLDocument doc;
    const char * path = "xml_teste.xml";
    char amountText[100];
    bool loadOk = doc.LoadFile(path);
    XMLElement * pRootElement = doc.RootElement();
    if (loadOk == XML_SUCCESS) {
        XMLElement * s = doc.FirstChildElement( "world" );
        
        //retirar atributos da window
        //retirar atributos da camera
            //posição
            //lookat

    } else {
        cout << "Erro ao ler ficheiro XML->" << path;
    }

/*
// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("nice c0ck");
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	
// put here the registration of the keyboard callbacks
	glutKeyboardFunc(keyboardCtrl);
	glutMouseFunc(mouseCtrl);


//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
// enter GLUT's main cycle
	glutMainLoop();
	*/
	return 1;
}
