#ifndef UTILS_XML_PARSER_HELPER_H
#define UTILS_XML_PARPER_HELPER_H

#include <iostream>
#include <string>

using namespace std;

enum XMLTags {WINDOW, CAMERA, LIGHTS, GROUP};

enum XMLTags get_xml_tag(string XMLTag);

#endif