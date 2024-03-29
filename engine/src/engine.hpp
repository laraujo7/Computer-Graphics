#ifndef ENGINE_H
#define ENGINE_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include "../../utils/generic_functions/generic_functions.hpp"
#include "../lib/glew/glew.h"
#include "../utils/direction_helpers/direction_helpers.hpp"
#include "classes/camera/camera.hpp"
#include "classes/world/world.hpp"
#include <GL/glut.h>
#endif

using namespace std;
using namespace tinyxml2;

#endif