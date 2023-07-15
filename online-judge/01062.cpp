#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int case_i = 1;

  while (true) {
    string s;
    getline(cin, s);

    if (s[0] == 'e')
      break;

    int n = s.size();

    vector<stack<char>> places;

    for (int i = 0; i < n; ++i) {
      char container = s[i];

      int best_place_i = -1;

      for (int place_i = 0; place_i < int(places.size()); ++place_i) {
        stack<char>& place = places[place_i];
        if (place.top() < container)
          continue;

        if (best_place_i == -1 || place.top() < places[best_place_i].top()) {
          best_place_i = place_i;
        }
      }

      if (best_place_i == -1) {
        places.push_back(stack<char>({container}));
        continue;
      }

      if (places[best_place_i].top() == container) {
        // it will not matter so we can just skip this container
        continue;
      }

      places[best_place_i].push(container);
    }

    cout << "Case " << case_i << ": " << places.size() << '\n';
    ++case_i;
  }
}
