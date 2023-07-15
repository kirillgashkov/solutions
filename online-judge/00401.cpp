#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;

bool is_palindrome(string& word) {
  int last_i = int(word.size()) - 1;

  for (int i = 0; i < ceil(word.size() / 2.0); ++i) {
    if (word[i] != word[last_i - i])
      return false;
  }

  return true;
}

const unordered_map<char, char> MIRROR_LETTERS({
    {'A', 'A'}, {'E', '3'}, {'H', 'H'}, {'I', 'I'}, {'J', 'L'}, {'L', 'J'},
    {'M', 'M'}, {'O', 'O'}, {'S', '2'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'},
    {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'}, {'1', '1'}, {'2', 'S'},
    {'3', 'E'}, {'5', 'Z'}, {'8', '8'},
});

bool is_mirrored(string& word) {
  int last_i = int(word.size()) - 1;

  for (int i = 0; i < ceil(word.size() / 2.0); ++i) {
    if (MIRROR_LETTERS.find(word[i]) == MIRROR_LETTERS.end())
      return false;
    if (MIRROR_LETTERS.at(word[i]) != word[last_i - i])
      return false;
  }

  return true;
}

int main() {
  string word;

  while (cin >> word) {
    bool palindrome = is_palindrome(word);
    bool mirrored = is_mirrored(word);

    if (palindrome and mirrored) {
      cout << word << " -- is a mirrored palindrome.\n";
    } else if (palindrome) {
      cout << word << " -- is a regular palindrome.\n";
    } else if (mirrored) {
      cout << word << " -- is a mirrored string.\n";
    } else {
      cout << word << " -- is not a palindrome.\n";
    }
    cout << '\n';
  }
}
