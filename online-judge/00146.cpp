#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  while (true) {
    string code;
    cin >> code;

    if (code == "#")
      break;

    string sorted_code(code);
    sort(sorted_code.begin(), sorted_code.end());

    string next_code(code);
    next_permutation(next_code.begin(), next_code.end());

    if (sorted_code == next_code) {
      cout << "No Successor\n";
    } else {
      cout << next_code << '\n';
    }
  }
}
