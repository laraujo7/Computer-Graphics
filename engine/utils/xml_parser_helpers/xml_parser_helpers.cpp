#include "xml_parser_helpers.hpp"

enum XMLTags get_xml_tag(string tag) {
  if(!tag.compare("world")) return WORLD;
  if(!tag.compare("window")) return WINDOW;
  if(!tag.compare("position")) return POSITION;
  if(!tag.compare("lookAt")) return LOOKAT;
  if(!tag.compare("up")) return UP;
  if(!tag.compare("projection")) return PROJECTION;
  if(!tag.compare("camera")) return CAMERA;
  if(!tag.compare("lights")) return LIGHTS;
  if(!tag.compare("light")) return LIGHT;
  if(!tag.compare("group")) return GROUP;
  if(!tag.compare("models")) return MODELS;
  if(!tag.compare("model")) return MODEL;
  if(!tag.compare("transform")) return TRANSFORM;
  if(!tag.compare("texture")) return TEXTURE;
  if(!tag.compare("scale")) return SCALE;
  if(!tag.compare("translate")) return TRANSLATE;
  if(!tag.compare("rotate")) return ROTATE;
  if(!tag.compare("color")) return COLOR;
  if(!tag.compare("diffuse")) return DIFFUSE;
  if(!tag.compare("ambient")) return AMBIENT;
  if(!tag.compare("specular")) return SPECULAR;
  if(!tag.compare("emissive")) return EMISSIVE;
  if(!tag.compare("shininess")) return SHININESS;
  println("XMLtag not found, default tag: world");
  return WORLD;
}