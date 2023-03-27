#ifndef UTILS_DIRECTION_HELPER_H
#define UTILS_DIRECTION_HELPER_H

#include "../../../utils/generic_functions/generic_functions.hpp"

#include <iostream>
#include <string>

using namespace std;

enum Direction {FRONT, BACK, RIGHT, LEFT};

enum Direction get_direction(string direction);

#endif