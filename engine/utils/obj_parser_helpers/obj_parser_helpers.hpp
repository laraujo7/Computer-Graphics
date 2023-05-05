#ifndef UTILS_OBJ_PARSER_HELPERS_H
#define UTILS_OBJ_PARSER_HELPERS_H

#include "../../../utils/generic_functions/generic_functions.hpp"

#include <iostream>
#include <string>

using namespace std;

enum ObjTags {VERTEX, VERTEX_TEXTURE, VERTEX_NORMAL, FACE, MTLLIB, USEMTL, NONE};

enum ObjTags get_obj_tag(string ObjTag);

#endif