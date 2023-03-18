#ifndef TRIANGLE_INDEX_H
#define TRIANGLE_INDEX_H

#include <bits/stdc++.h>

using namespace std;

class TriangleIndex {
private:
  tuple<int, int, int> triangle_indexs;

public:
  TriangleIndex();

  TriangleIndex(tuple<int, int, int> triangle_indexs);

  TriangleIndex(int indexOne, int indexTwo, int indexThree);

  int get_first_index();

  int get_secong_index();

  int get_third_index();

  string triangle_indexs_to_string();
};

#endif