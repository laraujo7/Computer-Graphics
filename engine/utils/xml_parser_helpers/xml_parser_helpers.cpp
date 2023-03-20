#include "xml_parser_helpers.hpp"

enum XMLTags get_xml_tag(string tag) {
  if(!tag.compare("window")) return WINDOW;
  if(!tag.compare("camera")) return CAMERA;
  if(!tag.compare("lights")) return LIGHTS;
  if(!tag.compare("group")) return GROUP;
  return WINDOW;
}