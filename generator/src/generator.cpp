#include "generator.h"

static const char USAGE[] =
    R"(Generator.

    Usage:
      generator sphere <radius> <slices> <stacks> <file>
      generator box <length> <grid> <file>
      generator cone <radius> <height> <slices> <stacks> <file>
      generator plane <length> <divisions> <file>
      generator (-h | --help)
      generator (-v | --version)

    Options:
      -h --help        Show this screen.
      -v --version     Show version.
)";

int main(int argc, char **argv) {

  std::map<std::string, docopt::value> args =
      docopt::docopt(USAGE, {argv + 1, argv + argc},
                     true,             // show help if requested
                     "Generator 1.0"); // version string

  if (args["sphere"].asBool()) {
    println("sphere");
  } else if (args["box"].asBool()) {
    println("box");
  } else if (args["cone"].asBool()) {
    println("cone");
  } else if (args["plane"].asBool()) {
    create_plane(stof(args["<length>"].asString()),
                 stoi(args["<divisions>"].asString()),
                 args["<file>"].asString());
  }
  return 0;
}