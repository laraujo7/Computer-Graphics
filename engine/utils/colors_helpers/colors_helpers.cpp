#include "colors_helpers.hpp"

void set_glcolor3f(string color) {
  if(!color.compare("sun")) return MandarinOrange;
  if(!color.compare("mercury")) return CadetBlue;
  if(!color.compare("venus")) return Orange;
  if(!color.compare("earth")) return SkyBlue;
  if(!color.compare("mars")) return Firebrick;
  if(!color.compare("jupiter")) return MandarinOrange;
  if(!color.compare("saturn")) return MediumWood;
  if(!color.compare("uranus")) return Turquoise;
  if(!color.compare("neptune")) return SteelBlue;
  if(!color.compare("pluto")) return LightGray;
  if(!color.compare("moon")) return VLightGray;
  return Gray;
}
