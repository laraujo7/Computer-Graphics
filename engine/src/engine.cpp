#include "engine.hpp"

World *world = new World();
int timebase, timecount, fps;
float frames;

void changeSize(int w, int h) {

  // Prevent a divide by zero, when window is too short
  // (you cant make a window with zero width).
  if (h == 0)
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
  gluPerspective(45.0f, ratio, 1.0f, 1000.0f);

  // return to the model view matrix mode
  glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {

  // clear buffers
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // set the camera
  glLoadIdentity();
  tuple<float, float, float> camera_poition =
      world->get_camera()->get_position();
  tuple<float, float, float> camera_look_at =
      world->get_camera()->get_look_at();

  gluLookAt(get<0>(camera_poition), get<1>(camera_poition),
            get<2>(camera_poition), get<0>(camera_look_at),
            get<1>(camera_look_at), get<2>(camera_look_at), 0.0f, 1.0f, 0.0f);

  glRotatef(0, get<0>(camera_poition), get<1>(camera_poition),
            get<2>(camera_poition));

  // glutWireTeapot(5);
  world->get_model()->draw();

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

  if (argc != 2) {
    println("Invalid number of arguments");
    return -1;
  }

  // init GLUT and the window
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(800, 800);
  timebase = glutGet(GLUT_ELAPSED_TIME);
  glutCreateWindow("Engine");

  // Required callback registry
  glutDisplayFunc(renderScene);
  glutIdleFunc(renderScene);
  glutReshapeFunc(changeSize);

// put here the registration of the keyboard callbacks
// glutKeyboardFunc(keyboardCtrl);
// glutMouseFunc(mouseCtrl);
#ifndef __APPLE__
  glewInit();
#endif

  //  OpenGL settings
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  world->load_XML(argv[1]);
  // enter GLUT's main cycle
  glutMainLoop();

  return 1;
}
