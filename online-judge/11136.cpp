#include <iostream>
#include <set>
using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;

    if (n == 0) {
      break;
    }

    long long total_cost = 0;

    multiset<int> bills;

    for (int i = 0; i < n; ++i) {
      int m;
      cin >> m;

      for (int j = 0; j < m; ++j) {
        int a;
        cin >> a;
        bills.insert(a);
      }

      auto max_iter = bills.end();
      --max_iter;
      auto min_iter = bills.begin();

      int cost = *max_iter - *min_iter;

      bills.erase(max_iter);
      bills.erase(min_iter);

      total_cost += cost;
    }

    cout << total_cost << '\n';
  }
}
