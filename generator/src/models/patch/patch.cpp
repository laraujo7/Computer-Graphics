#include "./patch.hpp"

vector<vector<float>> bezier_matrix = {{-1.0f, 3.0f, -3.0f, 1.0f},
                                       {3.0f, -6.0f, 3.0f, 0.0f},
                                       {-3.0f, 3.0f, 0.0f, 0.0f},
                                       {1.0f, 0.0f, 0.0f, 0.0f}};

void get_control_points_patches(
    vector<vector<int>> patches, vector<Point> control_points,
    vector<vector<vector<vector<float>>>> &control_points_patches) {

  for (vector<int> patch : patches) {
    vector<vector<float>> matrix_x;
    vector<vector<float>> matrix_y;
    vector<vector<float>> matrix_z;

    for (int i = 0; i < patch.size(); i += 4) {
      matrix_x.push_back({control_points[patch[i]].get_x(),
                          control_points[patch[i + 1]].get_x(),
                          control_points[patch[i + 2]].get_x(),
                          control_points[patch[i + 3]].get_x()});
      matrix_y.push_back({control_points[patch[i]].get_y(),
                          control_points[patch[i + 1]].get_y(),
                          control_points[patch[i + 2]].get_y(),
                          control_points[patch[i + 3]].get_y()});
      matrix_z.push_back({control_points[patch[i]].get_z(),
                          control_points[patch[i + 1]].get_z(),
                          control_points[patch[i + 2]].get_z(),
                          control_points[patch[i + 3]].get_z()});
    }

    control_points_patches.push_back({matrix_x, matrix_y, matrix_z});
  }
}

void read_patch_file(
    string file_input,
    vector<vector<vector<vector<float>>>> &control_points_patches) {
  vector<vector<int>> patches;
  vector<Point> points;

  ifstream file(file_input);

  if (!file.is_open()) {
    throw invalid_argument("Couldn't open the provided file");
  }

  int num_patches = stoi(get_file_line(file));

  for (int i = 0; i < num_patches; i++) {
    string str_patches = get_file_line(file);
    patches.push_back(tokenize_to_int(str_patches, ','));
  }

  int num_points = stoi(get_file_line(file));

  for (int i = 0; i < num_points; i++) {
    string str_points = get_file_line(file);
    points.push_back(Point(tokenize_to_float(str_points, ',')));
  }

  get_control_points_patches(patches, points, control_points_patches);
}

Point getBezier(float u, float t,
                vector<vector<vector<float>>> control_points) {
  vector<float> vector_u = {u * u * u, u * u, u, 1};
  vector<vector<float>> vector_t = {{t * t * t}, {t * t}, {t}, {1}};

  vector<vector<float>> pre_calculated_matrix_u =
      multiple_matrices(vector_u, bezier_matrix);

  vector<vector<float>> bezier_matrix_points_x =
      multiple_matrices(pre_calculated_matrix_u, control_points[0]);
  vector<vector<float>> bezier_matrix_points_y =
      multiple_matrices(pre_calculated_matrix_u, control_points[1]);
  vector<vector<float>> bezier_matrix_points_z =
      multiple_matrices(pre_calculated_matrix_u, control_points[2]);

  bezier_matrix_points_x =
      multiple_matrices(bezier_matrix_points_x, bezier_matrix);
  bezier_matrix_points_y =
      multiple_matrices(bezier_matrix_points_y, bezier_matrix);
  bezier_matrix_points_z =
      multiple_matrices(bezier_matrix_points_z, bezier_matrix);

  float x = multiple_matrices(bezier_matrix_points_x, vector_t).at(0).at(0);
  float y = multiple_matrices(bezier_matrix_points_y, vector_t).at(0).at(0);
  float z = multiple_matrices(bezier_matrix_points_z, vector_t).at(0).at(0);

  return Point(x, y, z);
}

void get_patch_points(
    int tessellation,
    vector<vector<vector<vector<float>>>> control_points_patches,
    vector<Point> &points) {
  for (vector<vector<vector<float>>> control_points_patch :
       control_points_patches) {
    for (int i = 0; i <= tessellation; i++) {
      for (int j = 0; j <= tessellation; j++) {
        float u = i / (float)tessellation;
        float t = j / (float)tessellation;

        points.push_back(getBezier(u, t, control_points_patch));
      }
    }
  }
}

void get_patch_indexes(int tessellation, int num_points,
                       vector<TriangleIndex> &triangules_indexs) {
  int num_indexes_per_patch = (tessellation + 1) * (tessellation + 1);

  // j is the current_patch
  for (int i = 0, j = 0; i < num_points; i += 16, j++) {
    for (int u = 0; u < tessellation; u++) {
      for (int t = 0; t < tessellation; t++) {
        int p1_x = j * num_indexes_per_patch + ((tessellation + 1) * u) + t;
        int p1_y = j * num_indexes_per_patch + (tessellation + 1) * (u + 1) + t;
        int p1_z = p1_x + 1;
        triangules_indexs.push_back(TriangleIndex(p1_x, p1_y, p1_z));

        int p2_y = p1_y + 1;
        triangules_indexs.push_back(TriangleIndex(p1_y, p2_y, p1_z));
      }
    }
  }
}

int create_patch(string file_input, int tessellation, string file_name) {
  vector<vector<vector<vector<float>>>> control_points_patches;
  vector<Point> points;
  vector<TriangleIndex> triangules_indexs;

  read_patch_file(file_input, control_points_patches);
  get_patch_points(tessellation, control_points_patches, points);
  get_patch_indexes(tessellation, points.size(), triangules_indexs);

  Model model(points, triangules_indexs);
  model.write_to_file(file_name, "patch");

  return 0;
}
