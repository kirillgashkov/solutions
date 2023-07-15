#include <iostream>

using namespace std;

int get_snail_day(int H, int U, int D, int F) {
  float current_H = 0;
  float current_day = 0;
  float U_with_F = U;
  float distance_fatigue = ((float)F / 100.0) * U;
  while (true) {
    ++current_day;
    current_H += U_with_F;
    if (U_with_F != 0) {
      U_with_F -= distance_fatigue;
      if (U_with_F < 0) {
        U_with_F = 0;
      }
    }
    if (current_H > H) {
      return current_day;
    }
    current_H -= D;
    if (current_H < 0) {
      return -current_day;
    }
  }
  return 0;
}

int main() {
  int H;
  int U;
  int D;
  int F;

  cin >> H >> U >> D >> F;
  while (H) {
    int day = get_snail_day(H, U, D, F);
    if (day > 0) {
      cout << "success on day " << day << '\n';
    } else {
      cout << "failure on day " << -day << '\n';
    }
    cin >> H >> U >> D >> F;
  }
}
