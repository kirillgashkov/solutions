#include <bitset>
#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

#define ii pair<int, int>

int main() {
  while (true) {
    int n;
    cin >> n;

    if (!cin)
      break;

    unordered_map<bitset<14>, ii> vertices;  // weight, potency per vertex

    for (int i = 0; i < (1 << n); ++i) {
      int weight;
      cin >> weight;

      vertices[bitset<14>(i)] = {weight, 0};
    }

    for (auto& vertex_and_weight : vertices) {
      auto vertex = const_cast<bitset<14>&>(vertex_and_weight.first);

      int potency = 0;

      for (int j = 0; j < n; ++j) {
        vertex[j] = !vertex[j];
        potency += vertices[vertex].first;
        vertex[j] = !vertex[j];
      }

      vertices[vertex].second = potency;
    }

    int max_potency_sum = -1;

    for (auto& vertex_and_weight : vertices) {
      auto vertex = const_cast<bitset<14>&>(vertex_and_weight.first);
      int root_potency = vertices[vertex].second;

      int potency_sum = 0;

      for (int j = 0; j < n; ++j) {
        vertex[j] = !vertex[j];

        potency_sum = root_potency + vertices[vertex].second;

        if (potency_sum > max_potency_sum) {
          max_potency_sum = potency_sum;
        }

        vertex[j] = !vertex[j];
      }
    }

    cout << max_potency_sum << '\n';
  }
}
