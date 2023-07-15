#include <functional>
#include <iostream>
#include <queue>
using namespace std;

#define intl unsigned long long

int main() {
  while (true) {
    int n;
    cin >> n;

    if (n == 0) {
      break;
    }

    priority_queue<int, vector<int>, greater<int>> nums;
    intl target_sum = 0;

    for (int i = 0; i < n; ++i) {
      int num;
      cin >> num;
      nums.push(num);
      target_sum += num;
    }

    intl cost = 0;

    while (true) {
      int sum = nums.top();
      nums.pop();
      sum += nums.top();
      nums.pop();

      cost += sum;

      if (sum == target_sum) {
        break;
      }

      nums.push(sum);
    }

    cout << cost << '\n';
  }
}
