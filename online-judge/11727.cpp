#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    vector<int> salaries;
    for (int j = 0; j < 3; ++j) {
      int s;
      cin >> s;
      salaries.push_back(s);
    }
    sort(salaries.begin(), salaries.end());
    cout << "Case " << i << ": " << salaries[1] << '\n';
  }
}
