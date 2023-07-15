#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

#define INF 1000000000;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(int argc, char const* argv[]) {
  ifstream fin("input.txt");
  int n;
  fin >> n;

  vi nums;
  for (int i = 0; i < n; ++i) {
    srand(random_device()());
    nums.push_back(rand());
  }

  sort(nums.begin(), nums.end());
  auto new_end = unique(nums.begin(), nums.end());
  nums.erase(new_end, nums.end());

  for (auto& num : nums) {
    cout << num << ' ';
  }
  cout << '\n';
  return 0;
}
