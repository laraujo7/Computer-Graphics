#ifndef UTILS_XML_PARSER_HELPER_H
#define UTILS_XML_PARPER_HELPER_H

#include <iostream>
#include <string>

using namespace std;

enum XMLTags {WORLD, WINDOW, CAMERA, POSITION, LOOKAT, UP, PROJECTION, LIGHTS, LIGHT, GROUP, MODELS, MODEL, TRANSFORM, TEXTURE, SCALE, TRANSLATE, ROTATE};

enum XMLTags get_xml_tag(string XMLTag);

#endif