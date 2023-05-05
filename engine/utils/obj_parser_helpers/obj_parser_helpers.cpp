#include "obj_parser_helpers.hpp"

enum ObjTags get_obj_tag(string tag) {
  if(!tag.compare("v")) return VERTEX;
  if(!tag.compare("vt")) return VERTEX_TEXTURE;
  if(!tag.compare("vn")) return VERTEX_NORMAL;
  if(!tag.compare("f")) return FACE;
  if(!tag.compare("mtllib")) return MTLLIB;
  if(!tag.compare("usemtl")) return USEMTL;
  println("XMLtag not found, default tag: none");
  return NONE;
}

