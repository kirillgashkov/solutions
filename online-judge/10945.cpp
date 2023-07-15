#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_palindrome(vector<char>& chars) {
  int last_i = int(chars.size()) - 1;

  for (int i = 0; i < ceil(chars.size() / 2.0); ++i) {
    if (chars[i] != chars[last_i - i])
      return false;
  }

  return true;
}

int main() {
  while (true) {
    string sentence;
    getline(cin >> ws, sentence);

    if (sentence == "DONE") {
      break;
    }

    vector<char> letters;

    for (auto& c : sentence) {
      switch (c) {
        case '.':
        case ',':
        case '!':
        case '?':
        case ' ':
          continue;
        default:
          letters.push_back(tolower(c));
          break;
      }
    }

    if (is_palindrome(letters)) {
      cout << "You won't be eaten!\n";
    } else {
      cout << "Uh oh..\n";
    }
  }
}
