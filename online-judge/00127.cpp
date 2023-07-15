#include <iostream>
#include <vector>
using namespace std;

struct Card {
  char suit;
  char rank;

  Card(string& raw) {
    suit = raw[0];
    rank = raw[1];
  }

  bool check_match(Card& card) {
    return card.suit == suit or card.rank == rank;
  }
};

void move_card(vector<vector<Card>>& piles, int from_pile_i, int to_pile_i) {
  auto& from_pile = piles[from_pile_i];
  auto& to_pile = piles[to_pile_i];

  to_pile.push_back(from_pile.back());
  from_pile.pop_back();

  if (from_pile.empty()) {
    piles.erase(piles.begin() + from_pile_i);
  }
}

bool try_moving_card(vector<vector<Card>>& piles, int pile_i) {
  Card& card = piles[pile_i].back();

  int third_pile_i = pile_i - 3;
  int first_pile_i = pile_i - 1;

  if (third_pile_i >= 0 and card.check_match(piles[third_pile_i].back())) {
    move_card(piles, pile_i, third_pile_i);
    return true;
  }

  if (first_pile_i >= 0 and card.check_match(piles[first_pile_i].back())) {
    move_card(piles, pile_i, first_pile_i);
    return true;
  }

  return false;
}

// returns true if moved something
bool try_moving_in_piles(vector<vector<Card>>& piles) {
  for (int i = 0; i < int(piles.size()); ++i) {
    if (try_moving_card(piles, i))
      return true;
  }

  return false;
}

int main() {
  while (true) {
    string raw_card;
    cin >> raw_card;

    if (raw_card == "#")
      break;

    vector<vector<Card>> piles = {{Card(raw_card)}};

    for (int i = 1; i < 52; ++i) {
      cin >> raw_card;
      piles.push_back({Card(raw_card)});
    }

    while (try_moving_in_piles(piles)) {
    }

    if (piles.size() == 1) {
      cout << piles.size() << " pile remaining:";
    } else {
      cout << piles.size() << " piles remaining:";
    }
    for (auto& pile : piles) {
      cout << ' ' << pile.size();
    }
    cout << '\n';
  }
}
