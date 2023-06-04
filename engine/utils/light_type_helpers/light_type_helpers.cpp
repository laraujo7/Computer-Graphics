#include "light_type_helpers.hpp"

enum LightType get_light_type(string light_type) {
  if(!light_type.compare("point")) return POINT;
  if(!light_type.compare("directional")) return DIRECTIONAL;
  if(!light_type.compare("spot")) return SPOTLIGHT;
  println("Light type not found, default light type: point");
  return POINT;
}
