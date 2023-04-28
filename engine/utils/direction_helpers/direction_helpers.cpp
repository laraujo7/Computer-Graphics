#include "direction_helpers.hpp"

enum Direction get_direction(string direction) {
  if(!direction.compare("front")) return FRONT;
  if(!direction.compare("back")) return BACK;
  if(!direction.compare("right")) return RIGHT;
  if(!direction.compare("left")) return LEFT;
  println("Direction not found, default direction: front");
  return FRONT;
}
