#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;


int string_to_card(string& s) {
    int card = 0;

    switch (s[0]) {
    case 'A': card += 1; break;
    case '2': card += 2; break;
    case '3': card += 3; break;
    case '4': card += 4; break;
    case '5': card += 5; break;
    case '6': card += 6; break;
    case '7': card += 7; break;
    case '8': card += 8; break;
    case '9': card += 9; break;
    case 'T': card += 10; break;
    case 'J': card += 11; break;
    case 'Q': card += 12; break;
    case 'K': card += 13; break;
    }
    switch (s[1]) {
    case 'S': card += 0 * 100; break;
    case 'H': card += 1 * 100; break;
    case 'D': card += 2 * 100; break;
    case 'C': card += 3 * 100; break;
    }

    return card;
}


string card_to_string(int& card) {
    string s;

    int rank = card % 100;
    int suit = card / 100;

    switch (rank) {
    case 1: s.push_back('A'); break;
    case 2: s.push_back('2'); break;
    case 3: s.push_back('3'); break;
    case 4: s.push_back('4'); break;
    case 5: s.push_back('5'); break;
    case 6: s.push_back('6'); break;
    case 7: s.push_back('7'); break;
    case 8: s.push_back('8'); break;
    case 9: s.push_back('9'); break;
    case 10: s.push_back('T'); break;
    case 11: s.push_back('J'); break;
    case 12: s.push_back('Q'); break;
    case 13: s.push_back('K'); break;
    }
    switch (suit) {
    case 0: s.push_back('S'); break;
    case 1: s.push_back('H'); break;
    case 2: s.push_back('D'); break;
    case 3: s.push_back('C'); break;
    }

    return s;
}


int value_of_card(int& card) {
    int rank = card % 100;
    if (rank < 10 && rank != 1) {
        return rank;
    } else {
        return 10;
    }
}


int main() {
    int n;
    cin >> n;
    for (int j = 1; j <= n; ++j) {
        vi deck_cards;
        for (int i = 0; i < 27; ++i) {
            string card_s;
            cin >> card_s;
            int card = string_to_card(card_s);
            deck_cards.push_back(card);
        }

        int deck_last_i = 26;
        int y = 0;
        for (int i = 0; i < 3; ++i) {
            int x = value_of_card(deck_cards[deck_last_i]);
            y += x;
            deck_last_i -= 11 - x;
            deck_cards.erase(deck_cards.begin() + deck_last_i + 1, deck_cards.end());
        }

        for (int i = 0; i < 25; ++i) {
            string card_s;
            cin >> card_s;
            int card = string_to_card(card_s);
            deck_cards.push_back(card);
        }

        int card_y_from_bottom = deck_cards[y - 1];

        cout << "Case " << j << ": " << card_to_string(card_y_from_bottom) << '\n';
    }

}
