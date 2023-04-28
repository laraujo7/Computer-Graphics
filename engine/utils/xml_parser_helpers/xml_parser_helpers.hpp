#ifndef UTILS_XML_PARSER_HELPERS_H
#define UTILS_XML_PARSER_HELPERS_H

#include "../../../utils/generic_functions/generic_functions.hpp"

#include <iostream>
#include <string>

using namespace std;

enum XMLTags {WORLD, WINDOW, CAMERA, POSITION, LOOKAT, UP, PROJECTION, LIGHTS, LIGHT, GROUP, MODELS, MODEL, TRANSFORM, TEXTURE, SCALE, TRANSLATE, ROTATE, COLOR, DIFFUSE, AMBIENT, SPECULAR, EMISSIVE, SHININESS};

enum XMLTags get_xml_tag(string XMLTag);

#endif