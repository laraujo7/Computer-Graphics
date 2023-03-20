#include "triangle_index.hpp"

TriangleIndex::TriangleIndex() {}

TriangleIndex::TriangleIndex(tuple<int, int, int> triangle_indexs) {
  this->triangle_indexs = triangle_indexs;
}

TriangleIndex::TriangleIndex(int indexOne, int indexTwo, int indexThree) {
  this->triangle_indexs = make_tuple(indexOne, indexTwo, indexThree);
}

int TriangleIndex::get_first_index() { return get<0>(this->triangle_indexs); }

int TriangleIndex::get_secong_index() { return get<1>(this->triangle_indexs); }

int TriangleIndex::get_third_index() { return get<2>(this->triangle_indexs); }

string TriangleIndex::triangle_indexs_to_string() {
  return to_string(this->get_first_index()) + " " +
         to_string(this->get_secong_index()) + " " +
         to_string(this->get_third_index());
}