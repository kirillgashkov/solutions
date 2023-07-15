#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>
#define vc vector<char>

int transform_to_int(char& c) {
  if (int(c) >= 97) {
    return (int(c) - 32) * 2 + 1;
  } else {
    return int(c) * 2;
  }
}

char transform_to_char(int& i) {
  if ((i % 2) == 0) {
    return char(i / 2);
  } else {
    return char((i - 1) / 2 + 32);
  }
}

vi transform_to_ints(vc& chars) {
  vi ints;
  ints.reserve(chars.size());

  for (auto& c : chars) {
    ints.push_back(transform_to_int(c));
  }

  return ints;
}

vc transform_to_chars(vi& ints) {
  vc chars;
  chars.reserve(ints.size());

  for (auto& i : ints) {
    chars.push_back(transform_to_char(i));
  }

  return chars;
}

int main() {
  int case_n;
  cin >> case_n;

  for (int case_i = 0; case_i < case_n; ++case_i) {
    string word;
    cin >> word;

    vc chars(word.begin(), word.end());
    vi ints = transform_to_ints(chars);

    sort(ints.begin(), ints.end());

    do {
      chars = transform_to_chars(ints);
      word = string(chars.begin(), chars.end());
      cout << word << '\n';
    } while (next_permutation(ints.begin(), ints.end()));
  }
}
