#include "generator.h"

int main(int argc, char **argv) {


  if (argc<2) {
    cout << "Incorrect number of arguments. \n";
  }

  switch(strcmp(argv[1])) {
    case "box":
   
    break;

    case "cone":
    break;

    case "plane":
    if (argc == 5) {

    } else {
      cout << "Object choosen correctly, but the number of arguments is insufficient. \n\n"
    }
    break;

    case "sphere":
    break;

    default:
  }

  return 0;
}