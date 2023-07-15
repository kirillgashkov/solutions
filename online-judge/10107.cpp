#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define ull unsigned long long
#define vull vector<ull>

int main() {
  vull numbers;
  numbers.reserve(10000);

  while (true) {
    ull number;
    cin >> number;

    if (!cin)
      break;

    numbers.push_back(number);

    if (numbers.size() % 2 == 1) {
      auto mid_iter = numbers.begin() + numbers.size() / 2;
      nth_element(numbers.begin(), mid_iter, numbers.end());
      cout << *mid_iter << '\n';
    } else {
      auto mid_iter_1 = numbers.begin() + numbers.size() / 2;
      nth_element(numbers.begin(), mid_iter_1, numbers.end());
      ull mid_1 = *mid_iter_1;

      auto mid_iter_2 = mid_iter_1 - 1;
      nth_element(numbers.begin(), mid_iter_2, numbers.end());
      ull mid_2 = *mid_iter_2;

      cout << (mid_1 + mid_2) / 2 << '\n';
    }
  }
}
