#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>

int solve_for_1(vi& a, int n) {
  int the_min = 1000000001;
  for (int i = 0; i < n; ++i) {
    the_min = min(the_min, a[i]);
  }
  return the_min;
}

int solve_for_2(vi& a, int n) {
  vi pref;
  pref.resize(n);
  pref[0] = a[0];
  for (int i = 1; i < n; ++i) {
    pref[i] = min(pref[i - 1], a[i]);
  }

  vi suff;
  suff.resize(n);
  suff[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    suff[i] = min(pref[i + 1], a[i]);
  }

  int the_max = -1000000001;
  for (int i = 0; i < n - 1; ++i) {
    the_max = max(the_max, max(pref[i], suff[i + 1]));
  }

  return the_max;
}

int solve_for_else(vi& a, int n) {
  int the_max = -1000000001;
  for (int i = 0; i < n; ++i) {
    the_max = max(the_max, a[i]);
  }
  return the_max;
}

void solve() {
  int n, k;
  cin >> n >> k;

  vi a;
  a.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  int the_max;
  switch (k) {
    case 1:
      the_max = solve_for_1(a, n);
      break;
    case 2:
      the_max = solve_for_2(a, n);
      break;
    default:
      the_max = solve_for_else(a, n);
      break;
  }

  cout << the_max << '\n';
}

int main() {
  solve();
}