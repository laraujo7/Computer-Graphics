#ifndef UTILS_LIGHT_TYPE_HELPER_H
#define UTILS_LIGHT_TYPE_HELPER_H

#include "../../../utils/generic_functions/generic_functions.hpp"

#include <iostream>
#include <string>

using namespace std;

enum LightType {POINT, DIRECTIONAL, SPOTLIGHT};

enum LightType get_light_type(string light_type);

#endif