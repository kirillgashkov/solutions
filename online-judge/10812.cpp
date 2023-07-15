#include <iostream>
using namespace std;

int main() {
  int cases_n;
  cin >> cases_n;

  for (int case_i = 0; case_i < cases_n; ++case_i) {
    // let a >= b, a >= 0, b >= 0
    //
    // (1) a + b = s
    // (2) a - b = d => a = d + b
    //
    // d + b + b = s
    // 2b = s - d
    // b = (s - d) / 2
    //
    // if b < 0 or b is not whole: impossible
    // else: a = d + b

    int s, d;
    cin >> s >> d;

    int b = (s - d) / 2;
    int remainder = (s - d) % 2;

    if (b < 0 or remainder != 0) {
      cout << "impossible\n";
    } else {
      int a = d + b;
      cout << a << ' ' << b << '\n';
    }
  }
}
