#include <iostream>
using namespace std;

void output_answer(int n, int m, int k) {
  printf("%d knights may be placed on a %d row %d column board.\n", k, n, m);
}

int main() {
  int n, m;

  cin >> n >> m;
  while (not(n == 0 and m == 0)) {
    int a, b;
    if (n < m) {
      a = n;
      b = m;
    } else {
      a = m;
      b = n;
    }

    if (a == 1) {
      output_answer(n, m, b);
    } else if (a == 2) {
      int root_count = (b / 4) * 4;
      int rest_count = 0;
      switch (b % 4) {
        case 1:
          rest_count = 2;
          break;
        case 2:
        case 3:
          rest_count = 4;
          break;
        default:
          break;
      }
      output_answer(n, m, root_count + rest_count);
    } else {
      output_answer(n, m, (a * b / 2) + (a * b % 2));
    }

    cin >> n >> m;
  }
}
