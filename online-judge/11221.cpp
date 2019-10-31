#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;


int get_side_of_square_palindrome(vector<char>& chars) {
    double dirty_k = sqrt(chars.size());
    int k = int(dirty_k);

    if (dirty_k != k) {
        return -1;
    }


    int last_idx = int(chars.size()) - 1;

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            int idx1 = i + k*j;
            int idx2 = i*k + j;

            char c1 = chars[idx1];
            char c2 = chars[idx2];
            char c3 = chars[last_idx - idx1];
            char c4 = chars[last_idx - idx2];

            if (not (c1 == c2 and c2 == c3 and c3 == c4)) {
                return -1;
            }
        }
    }


    return k;
}


int main() {
    int case_n;
    cin >> case_n;

    for (int case_i = 0; case_i < case_n; ++case_i) {
        cout << "Case #" << case_i + 1 << ":\n";

        string sentence;
        getline(cin >> ws, sentence);


        vector<char> letters;

        for (auto& c : sentence) {
            switch (c) {
                case '.':
                case ',':
                case '!':
                case '?':
                case '(':
                case ')':
                case ' ':
                    continue;
                default:
                    letters.push_back(c);
                    break;
            }
        }


        int k = get_side_of_square_palindrome(letters);

        if (k == -1) {
            cout << "No magic :(\n";
        } else {
            cout << k << '\n';
        }
    }
}
