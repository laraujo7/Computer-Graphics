#include "generator.hpp"

static const char USAGE[] =
    R"(Generator.

    Usage:
      generator sphere <radius> <slices> <stacks> <file>
      generator box <length> <grid> <file>
      generator cone <radius> <height> <slices> <stacks> <file>
      generator plane <length> <divisions> <file>
      generator patch <file_input> <tessellation> <file_name>
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
    create_sphere(stof(args["<radius>"].asString()),
                  stoi(args["<slices>"].asString()),
                  stoi(args["<stacks>"].asString()), args["<file>"].asString());
  } else if (args["box"].asBool()) {
    create_box(stof(args["<length>"].asString()),
               stoi(args["<grid>"].asString()), args["<file>"].asString());
  } else if (args["cone"].asBool()) {
    create_cone(stof(args["<radius>"].asString()),
                stof(args["<height>"].asString()),
                stoi(args["<slices>"].asString()),
                stoi(args["<stacks>"].asString()), args["<file>"].asString());
  } else if (args["plane"].asBool()) {
    create_plane(stof(args["<length>"].asString()),
                 stoi(args["<divisions>"].asString()),
                 args["<file>"].asString());
  } else if (args["patch"].asBool()) {
    create_patch(args["<file_input>"].asString(),
                 stoi(args["<tessellation>"].asString()),
                 args["<file_name>"].asString());
  }

  return 0;
}