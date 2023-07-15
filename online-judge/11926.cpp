#include <bitset>
#include <iostream>
using namespace std;

int main() {
  while (true) {
    int n, m;
    cin >> n >> m;

    if (n == 0 and m == 0)
      break;

    bitset<1000000> calendar;
    bool has_conflict = false;

    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;

      for (int j = a; j < b; ++j) {
        if (calendar[j]) {
          has_conflict = true;
        }
        calendar[j] = true;
      }
    }

    for (int i = 0; i < m; ++i) {
      int a, b, s;
      cin >> a >> b >> s;

      while (a < 1000000) {
        if (b > 1000000)
          b = 1000000;

        for (int j = a; j < b; ++j) {
          if (calendar[j]) {
            has_conflict = true;
          }
          calendar[j] = true;
        }

        a += s;
        b += s;
      }
    }

    if (has_conflict) {
      cout << "CONFLICT\n";
    } else {
      cout << "NO CONFLICT\n";
    }
  }
}
