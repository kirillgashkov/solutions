#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define umap unordered_map
#define uset unordered_set

int main() {
  while (true) {
    umap<char, uset<char>> connections;
    uset<char> awakes;

    int n, m;
    cin >> n >> m;

    if (!cin)
      break;

    for (int i = 0; i < 3; ++i) {
      char awake;
      cin >> awake;
      awakes.insert(awake);
    }

    for (int j = 0; j < m; ++j) {
      char a, b;
      cin >> a >> b;

      if (connections.find(a) == connections.end())
        connections[a] = {};
      if (connections.find(b) == connections.end())
        connections[b] = {};

      connections[a].insert(b);
      connections[b].insert(a);
    }

    for (auto& awake : awakes) {
      connections.erase(awake);
    }

    int awoken_n = 3;
    int year_i = 0;

    // worst case scenario: each year an area wakes up (out of (n-3) sleeping
    // areas)
    while (true) {
      if (connections.empty()) {
        break;
      }

      vector<char> to_be_awoken;

      for (auto& area_n_connections : connections) {
        int awakes_k = 0;

        for (auto& connected_area : area_n_connections.second) {
          if (awakes.find(connected_area) != awakes.end()) {
            awakes_k += 1;

            if (awakes_k >= 3) {
              to_be_awoken.push_back(area_n_connections.first);
              break;
            }
          }
        }
      }

      year_i += 1;
      for (auto& awoken : to_be_awoken) {
        connections.erase(awoken);
        awakes.insert(awoken);
        awoken_n += 1;
      }

      if (to_be_awoken.empty()) {
        break;
      }
    }

    if (awoken_n == n) {
      cout << "WAKE UP IN, " << year_i << ", YEARS\n";
    } else {
      cout << "THIS BRAIN NEVER WAKES UP\n";
    }
  }
}
