#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


int main() {
    while (true) {
        int n;
        cin >> n;

        if (n == -1) {
            break;
        }

        string needed_word;
        getline(cin >> ws, needed_word);
        unordered_set<char> needed_chars(needed_word.begin(), needed_word.end());

        string guessed_str;
        getline(cin >> ws, guessed_str);
        vector<char> guessed_char_list(guessed_str.begin(), guessed_str.end());

        cout << "Round " << n << '\n';

        int mistakes_count = 0;

        for (auto& c : guessed_char_list) {
            if (needed_chars.find(c) != needed_chars.end()) {
                needed_chars.erase(c);
                if (needed_chars.empty()) {
                    cout << "You win.\n";
                    goto out;
                }
            } else {
                ++mistakes_count;
                if (mistakes_count == 7) {
                    cout << "You lose.\n";
                    goto out;
                }
            }
        }
        out:

        if (!needed_chars.empty() and mistakes_count != 7) {
            cout << "You chickened out.\n";
        }
    }
}
