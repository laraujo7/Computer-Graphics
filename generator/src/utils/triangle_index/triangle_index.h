#ifndef TRIANGLE_INDEX_H
#define TRIANGLE_INDEX_H

#include <bits/stdc++.h>

using namespace std;

class TriangleIndex {
private:
  tuple<int, int, int> triangle_indexs;

public:
  TriangleIndex() {}

  TriangleIndex(tuple<int, int, int> triangle_indexs) {
    this->triangle_indexs = triangle_indexs;
  }

  TriangleIndex(int indexOne, int indexTwo, int indexThree) {
    this->triangle_indexs = make_tuple(indexOne, indexTwo, indexThree);
  }

  int getFirstIndex() { return get<0>(this->triangle_indexs); }

  int getSecongIndex() { return get<1>(this->triangle_indexs); }

  int getThirdIndex() { return get<2>(this->triangle_indexs); }

  string triangle_indexs_to_string() {
    return to_string(this->getFirstIndex()) + " " +
           to_string(this->getSecongIndex()) + " " +
           to_string(this->getThirdIndex());
  }
};

#endif