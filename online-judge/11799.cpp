#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N;
    cin >> N;
    int max_s = -1;
    while (N) {
      --N;
      int s;
      cin >> s;
      if (s > max_s) {
        max_s = s;
      }
    }
    cout << "Case " << i << ": " << max_s << '\n';
  }
}
