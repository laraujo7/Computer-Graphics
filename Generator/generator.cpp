#include "generator.h"

int main(int argc, char **argv) {

  if (argc < 2) {
    cout << UNSUFFICIENT_ARGUMENT;
  }

  if(!strcmp(argv[1], "box")) {

  }
  else if(!strcmp(argv[1], "cone")) {

  }
  else if(!strcmp(argv[1], "plane")) {
    if (argc == 5) {

    } else {
      cout << OBJECT_FOUND_INSUFFICIENT_ARGUMENTS ;
    }
  }
  else if(!strcmp(argv[1], "sphere")) {

  }

  return 0;
}