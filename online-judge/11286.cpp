#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;

    if (n == 0) {
      break;
    }

    unordered_map<string, int> combo_counts;

    for (int i = 0; i < n; ++i) {
      vector<int> combination;
      combination.reserve(5);

      for (int j = 0; j < 5; ++j) {
        int course;
        cin >> course;
        combination.push_back(course);
      }

      sort(combination.begin(), combination.end());

      ostringstream combo;

      for (auto& course : combination) {
        combo << course;
      }

      if (combo_counts.find(combo.str()) == combo_counts.end()) {
        combo_counts[combo.str()] = 0;
      }

      combo_counts[combo.str()] += 1;
    }

    int max_count = -1;

    for (auto& combo_count : combo_counts) {
      max_count = max(max_count, combo_count.second);
    }

    int prize_count = 0;

    for (auto& combo_count : combo_counts) {
      prize_count += combo_count.second == max_count ? max_count : 0;
    }

    cout << prize_count << '\n';
  }
}
