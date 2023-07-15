#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

vector<vi> edge_list_2_adj_matrix(vector<pair<int, ii>>& edge_list,
                                  int v,
                                  int e) {
  vector<vi> adj_matrix;
  adj_matrix.resize(v);

  for (auto& vertex_list : adj_matrix) {
    vertex_list.resize(v);
  }

  for (auto& edge : edge_list) {
    int weight = edge.first;
    int v1 = edge.second.first;
    int v2 = edge.second.second;

    adj_matrix[v1][v2] = weight;
  }

  return adj_matrix;
}

vector<vii> edge_list_2_adj_list(vector<pair<int, ii>>& edge_list,
                                 int v,
                                 int e) {
  vector<vii> adj_list;
  adj_list.resize(v);

  for (auto& edge : edge_list) {
    int weight = edge.first;
    int v1 = edge.second.first;
    int v2 = edge.second.second;

    adj_list[v1].emplace_back(weight, v2);
  }

  return adj_list;
}

vector<pair<int, ii>> adj_matrix_2_edge_list(vector<vi>& adj_matrix,
                                             int v,
                                             int e) {
  vector<pair<int, ii>> edge_list;

  for (int v1 = 0; v1 < v; ++v1) {
    for (int v2 = 0; v2 < v; ++v2) {
      int weight = adj_matrix[v1][v2];

      if (weight != 0) {
        edge_list.emplace_back(weight, v1, v2);
      }
    }
  }

  return edge_list;
}

vector<vii> adj_matrix_2_adj_list(vector<vi>& adj_matrix, int v, int e) {
  vector<vii> adj_list;
  adj_list.resize(v);

  for (int v1 = 0; v1 < v; ++v1) {
    for (int v2 = 0; v2 < v; ++v2) {
      int weight = adj_matrix[v1][v2];

      if (weight != 0) {
        adj_list[v1].emplace_back(weight, v2);
      }
    }
  }

  return adj_list;
}

vector<pair<int, ii>> adj_list_2_edge_list(vector<vii>& adj_list,
                                           int v,
                                           int e) {
  vector<pair<int, ii>> edge_list;

  for (int v1 = 0; v1 < v; ++v1) {
    vii& vertex_list = adj_list[v1];

    for (auto& weight_n_vertex : vertex_list) {
      int weight = weight_n_vertex.first;
      int v2 = weight_n_vertex.second;

      edge_list.emplace_back(weight, v1, v2);
    }
  }

  return edge_list;
}

vector<vi> adj_list_2_adj_matrix(vector<vii>& adj_list, int v, int e) {
  vector<vi> adj_matrix;
  adj_matrix.resize(v);

  for (auto& vertex_list : adj_matrix) {
    vertex_list.resize(v);
  }

  for (int v1 = 0; v1 < v; ++v1) {
    vii& vertex_list = adj_list[v1];

    for (auto& weight_n_vertex : vertex_list) {
      int weight = weight_n_vertex.first;
      int v2 = weight_n_vertex.second;

      adj_matrix[v1][v2] = weight;
    }
  }

  return adj_matrix;
}

int main() {
  // 10
  // 1 2 6
  // 1 3 6
  // 1 4 6
  // 1 0 7
  // 2 0 7
  // 2 4 7
  // 2 3 3
  // 3 0 3
  // 3 4 3
  // 4 0 2

  int e;
  cin >> e;

  vector<pair<int, ii>> edge_list;
  edge_list.reserve(e);

  int v = -1;

  for (int i = 0; i < e; ++i) {
    int weight, v1, v2;
    cin >> weight >> v1 >> v2;

    v = max(v, max(v1, v2));

    edge_list.emplace_back(weight, v1, v2);
    edge_list.emplace_back(weight, v2, v1);
  }

  v += 1;

  // test conversions here
}
