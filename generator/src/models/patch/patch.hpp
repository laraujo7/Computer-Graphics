#ifndef PATCH_H
#define PATCH_H

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>

#include "../../../../utils/file_helpers/file_helpers.hpp"
#include "../../../../utils/generic_functions/generic_functions.hpp"
#include "../../../../utils/point/point.hpp"
#include "../../../../utils/string_helpers/string_helpers.hpp"
#include "../../../../utils/vector/vector.hpp"
#include "../../classes/model/model.hpp"
#include "../../classes/triangle_index/triangle_index.hpp"

int create_patch(string file_input, int tessellation, string file_output);

using namespace std;

#endif