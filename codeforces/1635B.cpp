#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>

bool is_local_maximum(vi& a, int i) {
  if (i + 1 >= a.size() || i - 1 < 0) {
    return false;
  }

  return a[i - 1] < a[i] && a[i] > a[i + 1];
}

int main() {
  int cases_count;
  cin >> cases_count;

  while (cases_count--) {
    int n;
    cin >> n;

    vi a;

    for (int i = 0; i < n; i++) {
      int number;
      cin >> number;
      a.push_back(number);
    }

    int swaps = 0;

    for (int i = 0; i < n; i++) {
      if (is_local_maximum(a, i)) {
        if (is_local_maximum(a, i + 2)) {
          int max_el;
          if (a[i] > a[i + 2]) {
            max_el = a[i];
          } else {
            max_el = a[i + 2];
          }
          a[i + 1] = max_el;
          i += 2;
          swaps += 1;
        } else {
          int max_neighbor;
          if (a[i + 1] > a[i - 1]) {
            max_neighbor = a[i + 1];
          } else {
            max_neighbor = a[i - 1];
          }

          a[i] = max_neighbor;
          i += 1;
          swaps += 1;
        }
      }
    }

    cout << swaps << '\n';
    for (int i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
