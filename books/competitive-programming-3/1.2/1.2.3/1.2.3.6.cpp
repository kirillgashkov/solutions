#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 1000000000;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(int argc, char const* argv[]) {
  ifstream fin("input.txt");

  int target = 23;
  fin >> target;

  int num;
  vi nums = {10, 15, 20, 25, 30, 35};
  while (fin >> num) {
    nums.push_back(num);
  }

  bool res = binary_search(nums.begin(), nums.end(), target);
  if (res) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}
