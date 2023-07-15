#include <iostream>
#include <vector>
using namespace std;

#define vc vector<char>
#define vvc vector<vc>

void input_square(vvc& square, int n) {
  square.reserve(n);

  for (int i = 0; i < n; ++i) {
    vc row;
    row.reserve(n);

    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      row.push_back(c);
    }

    square.push_back(row);
  }
}

// makes square rotated 90 degrees clockwise
vvc make_rotated_square(vvc& square) {
  vc default_row;
  default_row.assign(square.size(), 0);

  vvc rotated;
  rotated.assign(square.size(), default_row);

  int max_i = int(square.size()) - 1;

  for (int i = 0; i < int(square.size()); ++i) {
    for (int j = 0; j < int(square.size()); ++j) {
      rotated[j][max_i - i] = square[i][j];
    }
  }

  return rotated;
}

int count_squares(vvc& big, vvc& small, int big_n, int small_n) {
  int count = 0;

  int n_of_interest = big_n - small_n;

  for (int i = 0; i <= n_of_interest; ++i) {
    int i_of_interest = i + small_n;

    for (int j = 0; j <= n_of_interest; ++j) {
      int j_of_interest = j + small_n;

      for (int k = i; k < i_of_interest; ++k) {
        for (int l = j; l < j_of_interest; ++l) {
          if (small[k - i][l - j] != big[k][l])
            goto next_j_of_interest;
        }
      }

      ++count;

    next_j_of_interest:;
    }
  }

  return count;
}

int main() {
  while (true) {
    int big_n, small_n;
    cin >> big_n >> small_n;

    if (big_n == 0)
      break;

    vvc big;
    input_square(big, big_n);

    vector<vvc> smalls;
    smalls.resize(4);

    input_square(smalls[0], small_n);
    for (int i = 1; i < 4; ++i) {
      smalls[i] = make_rotated_square(smalls[i - 1]);
    }

    for (int small_i = 0; small_i < 3; ++small_i) {
      cout << count_squares(big, smalls[small_i], big_n, small_n) << ' ';
    }
    cout << count_squares(big, smalls[3], big_n, small_n) << '\n';
  }
}
