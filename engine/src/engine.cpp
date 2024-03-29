#include "engine.hpp"

World *world = new World();
int timebase, timecount, fps;
int frame = 0;
bool trajectory;
char s[30];

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
  tuple<float, float, float> camara_projection =
      world->get_camera()->get_projection();
  gluPerspective(get<0>(camara_projection), ratio, get<1>(camara_projection),
                 get<2>(camara_projection));

  // return to the model view matrix mode
  glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {

  int timet;

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  // clear buffers
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // set the camera
  glLoadIdentity();

  Camera *camera = world->get_camera();
  tuple<float, float, float> camera_position = camera->get_position();
  tuple<float, float, float> camera_look_at = camera->get_look_at();
  tuple<float, float, float> camera_up = camera->get_up();

  gluLookAt(get<0>(camera_position), get<1>(camera_position),
            get<2>(camera_position), get<0>(camera_look_at),
            get<1>(camera_look_at), get<2>(camera_look_at), get<0>(camera_up),
            get<1>(camera_up), get<2>(camera_up));

  frame++;
  timet = glutGet(GLUT_ELAPSED_TIME);
  if (timet - timebase > 1000) {
    sprintf(s, "FPS:%4.2f", frame * 1000.0 / (timet - timebase));
    timebase = timet;
    frame = 0;
    glutSetWindowTitle(s);
  }

  world->draw();

  // End of frame
  glutSwapBuffers();
}

// write function to process keyboard events
void keyboardCtrl(unsigned char key, int x, int y) {
  switch (key) {
  case 'w':
    world->get_camera()->move(get_direction("front"));
    break;
  case 's':
    world->get_camera()->move(get_direction("back"));
    break;
  case 'a':
    world->get_camera()->move(get_direction("left"));
    break;
  case 'd':
    world->get_camera()->move(get_direction("right"));
    break;
  case 't':
    world->set_trajectory();
    break;
  default:
    break;
    // case 'q':
    //                 angleAlpha += -50;
    // case 'e':
    //                 angleAlpha += 50;
  }
  glutPostRedisplay();
}
/*
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
  glutKeyboardFunc(keyboardCtrl);
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