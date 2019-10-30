#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define si unordered_set<int>


int main() {
    int cases_count;
    cin >> cases_count;

    for (int cs = 0; cs < cases_count; ++cs) {

        vvi bingo_card;
        bingo_card.resize(5);

        for (int i = 0; i < 5; ++i) {
            vi row;
            row.resize(5);

            if (i == 2) {
                for (int j = 0; j < 2; ++j) {
                    cin >> row[j];
                }
                row[2] = -1;
                for (int j = 3; j < 5; ++j) {
                    cin >> row[j];
                }
            } else {
                for (int j = 0; j < 5; ++j) {
                    cin >> row[j];
                }
            }

            bingo_card[i] = row;
        }


        vector<si> bingo_sets;

        // hor
        for (int i = 0; i < 5; ++i) {
            si bingo_set;
            for (int j = 0; j < 5; ++j) {
                if (bingo_card[i][j] == -1) continue;
                bingo_set.insert(bingo_card[i][j]);
            }
            bingo_sets.push_back(bingo_set);
        }

        // ver
        for (int j = 0; j < 5; ++j) {
            si bingo_set;
            for (int i = 0; i < 5; ++i) {
                if (bingo_card[i][j] == -1) continue;
                bingo_set.insert(bingo_card[i][j]);
            }
            bingo_sets.push_back(bingo_set);
        }

        // diag1
        si bingo_set_diag1;
        for (int l = 0; l < 5; ++l) {
            if (bingo_card[l][l] == -1) continue;
            bingo_set_diag1.insert(bingo_card[l][l]);
        }
        bingo_sets.push_back(bingo_set_diag1);

        // diag2
        si bingo_set_diag2;
        for (int l = 0; l < 5; ++l) {
            if (bingo_card[4-l][l] == -1) continue;
            bingo_set_diag2.insert(bingo_card[4-l][l]);
        }
        bingo_sets.push_back(bingo_set_diag2);


        vi bingo_numbers;
        bingo_numbers.resize(75);

        for (int i = 0; i < 75; ++i) {
            cin >> bingo_numbers[i];
        }


        int win_i = -1;

        for (int i = 0; i < 75; ++i) {
            int number = bingo_numbers[i];

            for (auto& bingo_set : bingo_sets) {
                bingo_set.erase(number);
                if (bingo_set.empty()) {
                    win_i = i;
                    goto out;
                }
            }
        }
        out:;


        cout << "BINGO after " << win_i + 1 << " numbers announced\n";
    }
}
