#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

typedef vector<int> vi;


int get_higher_card(int& card, unordered_set<int>& used_cards) {
    int higher_card = card + 1;
    while (used_cards.count(higher_card) != 0) {
        ++higher_card;
    }
    return higher_card;
}


int calc_cheat_card(vi& pbcards, vi& pgcards, unordered_set<int>& used_cards) {
    int wins_count = 0;
    int opponent_of_flexbc;
    for (int i = 0; i < 3; ++i) {
        if (pbcards[i] > pgcards[i]) {
            ++wins_count;
        }
        if (pbcards[i] == 0) {
            opponent_of_flexbc = pgcards[i];
        }
    }

    switch (wins_count) {
    case 0: return -1; // cannot win this
    case 1: return get_higher_card(opponent_of_flexbc, used_cards); // find cheat card
    }
    // no cheat card needed
    int normal_card = 1;
    while (used_cards.count(normal_card) != 0) {
        ++normal_card;
    }
    return normal_card;
}


int main() {
    int a, b, c, d, e;
    while (cin >> a >> b >> c >> d >> e) {
        if (a == 0) { break; }

        unordered_set<int> used_cards = {a, b, c, d, e};
        unordered_set<int> cheat_cards;

        vi bcards = {d, e, 0};
        vi gcards = {a, b, c};

        sort(bcards.begin(), bcards.end());
        sort(gcards.begin(), gcards.end());

        vector<vi> possible_bcards;
        vector<vi> possible_gcards;

        do {
            vi next_cards(bcards.begin(), bcards.end());
            possible_bcards.push_back(next_cards);
        } while (next_permutation(bcards.begin(), bcards.end()));
        do {
            vi next_cards(gcards.begin(), gcards.end());
            possible_gcards.push_back(next_cards);
        } while (next_permutation(gcards.begin(), gcards.end()));

        for (auto& pbcards : possible_bcards) {
            for (auto& pgcards : possible_gcards) {
                int cheat_card = calc_cheat_card(pbcards, pgcards, used_cards);
                cheat_cards.insert(cheat_card);
            }
        }

        if (cheat_cards.size() == 0) {
            cout << "-1\n";
        } else {
            int max_card = *max_element(cheat_cards.begin(), cheat_cards.end());
            if (cheat_cards.count(-1) != 0) {
                cout << "-1\n";
            } else if (max_card == 53) {
                cout << "-1\n";
            } else {
                cout << max_card << '\n';
            }
        }
    }
}
