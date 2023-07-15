#include <bitset>
#include <iostream>
using namespace std;

#define uintl unsigned long long

int main() {
  while (true) {
    uintl x;
    cin >> x;

    if (x == 0)
      break;

    bitset<32> x_bitset(x);

    bitset<32> a_bitset;
    bitset<32> b_bitset;

    bool filling_a = true;
    for (int i = 0; i < 32; ++i) {
      if (x_bitset[i] == true) {
        if (filling_a) {
          a_bitset[i] = true;
        } else {
          b_bitset[i] = true;
        }
        filling_a = !filling_a;
      }
    }

    cout << a_bitset.to_ullong() << ' ' << b_bitset.to_ullong() << '\n';
  }
}
