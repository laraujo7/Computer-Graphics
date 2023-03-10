#include "camera.hpp"
#include "includes.h"
#include "world.cpp"

World *world = new World();

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
	float pos[3], lookAt[3];
	world->getCamPosition(pos);
	world->getCamLookAt(lookAt);

	gluLookAt(pos[0],pos[1],pos[2], 
		      lookAt[0],lookAt[1],lookAt[2],
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
	
	glRotatef(0, pos[0], pos[1], pos[2]);

	glColor3f(1.0f, 0.0f, 0.0f);
	glutWireTeapot(5);
	

// put the geometric transformations here


// put pyramid drawing instructions here


	// End of frame
	glutSwapBuffers();
}


/*
// write function to process keyboard events
void keyboardCtrl(unsigned char key, int x, int y){

	switch(key) {
        case 'w':
			posZ += -10;
        case 's':
			posZ += 10;
        case 'a':
			posX += -10;
        case 'd':
			posX += 10;
        case 'q':
			angleAlpha += -50;
        case 'e':
			angleAlpha += 50;
    }
	glutPostRedisplay();
}

void mouseCtrl(int button, int state, int x, int y){
	if(state == GLUT_DOWN){
		angleAlpha += (x + y);
		posX = x;
		posY = y;
	}
	glutPostRedisplay();
}
*/
int main(int argc, char **argv) {

//  Reading XML config file and setting up
	
	
// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("Teste");
	//glewInit();
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);

	
// put here the registration of the keyboard callbacks
	//glutKeyboardFunc(keyboardCtrl);
	//glutMouseFunc(mouseCtrl);


//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	if(argc != 2){
		cout<< "Path de ficheiro de configuração desconhecido";
		return 0;
	}

	world->loadXML(argv[1]);
// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}
