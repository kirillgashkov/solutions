#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

struct UnionFind {
  unordered_map<char, char> p;
  unordered_map<char, int> r;

  void make_set(char v) { p[v] = v; }
  char find_set(char v) {
    if (p[v] == v) {
      return v;
    }
    return p[v] = find_set(p[v]);
  }
  void union_sets(char a, char b) {
    a = find_set(a);
    b = find_set(b);

    if (r[a] < r[b]) {
      swap(a, b);
    }
    p[b] = a;
    if (r[a] == r[b]) {
      r[a] += 1;
    }
  }
};

void handle_case() {
  vector<pair<char, char>> edges;

  while (true) {
    string raw_edge;
    getline(cin >> ws, raw_edge);

    if (raw_edge[0] == '*') {
      break;
    }

    char a, b;
    sscanf(raw_edge.c_str(), "(%c,%c)", &a, &b);

    edges.emplace_back(a, b);
  }

  UnionFind graph_sets;

  string raw_vertices;
  getline(cin, raw_vertices);
  for (auto& vertex : raw_vertices) {
    if (vertex == ',')
      continue;
    graph_sets.make_set(vertex);
  }

  for (auto& edge : edges) {
    graph_sets.union_sets(edge.first, edge.second);
  }

  unordered_map<char, int> graph_vertex_counts;

  for (auto& vertex_n_parent : graph_sets.p) {
    char parent = graph_sets.find_set(vertex_n_parent.first);

    if (graph_vertex_counts.find(parent) == graph_vertex_counts.end()) {
      graph_vertex_counts[parent] = 0;
    }
    graph_vertex_counts[parent] += 1;
  }

  int acorn_count = 0;

  for (auto& parent_n_count : graph_vertex_counts) {
    if (parent_n_count.second == 1) {
      acorn_count += 1;
    }
  }

  int tree_count = (int)graph_vertex_counts.size() - acorn_count;

  cout << "There are " << tree_count << " tree(s) and " << acorn_count
       << " acorn(s).\n";
}

int main() {
  int t;
  cin >> t;

  for (int i_t = 0; i_t < t; ++i_t) {
    handle_case();
  }
}
