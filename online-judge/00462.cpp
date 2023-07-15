#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define INF 1000000000;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int string_to_card(string& s) {
  int card;
  switch (s[0]) {
    case 'A':
      card = 1;
      break;
    case '2':
      card = 2;
      break;
    case '3':
      card = 3;
      break;
    case '4':
      card = 4;
      break;
    case '5':
      card = 5;
      break;
    case '6':
      card = 6;
      break;
    case '7':
      card = 7;
      break;
    case '8':
      card = 8;
      break;
    case '9':
      card = 9;
      break;
    case 'T':
      card = 10;
      break;
    case 'J':
      card = 11;
      break;
    case 'Q':
      card = 12;
      break;
    case 'K':
      card = 13;
      break;
  }
  switch (s[1]) {
    case 'S':
      card += 0;
      break;
    case 'H':
      card += 100;
      break;
    case 'D':
      card += 200;
      break;
    case 'C':
      card += 300;
      break;
  }
  return card;
}

vector<vi> group_by_suits(vi& cards) {
  vector<vi> suit_cards = {{}, {}, {}, {}};
  for (auto& card : cards) {
    int suit = card / 100;
    suit_cards[suit].push_back(card);
  }
  return suit_cards;
}

int calc_suit_points_1to4(vi& cards, int sz) {
  int points = 0;
  for (auto& card : cards) {
    int rank = card % 100;
    switch (rank) {
      case 1:
        points += 4;
        break;
      case 13:
        if (sz == 1) {
          points += 3 - 1;
        } else {
          points += 3;
        }
        break;
      case 12:
        if (sz <= 2) {
          points += 2 - 1;
        } else {
          points += 2;
        }
        break;
      case 11:
        if (sz <= 3) {
          points += 1 - 1;
        } else {
          points += 1;
        }
        break;
    }
  }
  return points;
}

bool calc_suit_is_stopped(vi& cards, int sz) {
  for (auto& card : cards) {
    int rank = card % 100;
    switch (rank) {
      case 1:
        return true;
      case 13:
        if (sz > 1) {
          return true;
        }
        break;
      case 12:
        if (sz > 2) {
          return true;
        }
        break;
    }
  }
  return false;
}

int calc_suit_points_5to7(int sz) {
  int points = 0;
  switch (sz) {
    case 2:
      points += 1;
      break;
    case 1:
      points += 2;
      break;
    case 0:
      points += 2;
      break;
  }
  return points;
}

int main() {
  string cards_s;
  while (getline(cin >> ws, cards_s)) {
    istringstream cards_s_stream(cards_s);
    vector<vi> suit_cards = {{}, {}, {}, {}};
    vi suit_points_1to4;
    vi suit_points_5to7;
    vi suit_sizes;
    vector<bool> suit_is_stopped;

    for (int i = 0; i < 13; ++i) {
      string card_s;
      cards_s_stream >> card_s;
      int card = string_to_card(card_s);
      int suit = card / 100;
      suit_cards[suit].push_back(card);
    }

    for (auto& cards : suit_cards) {
      int sz = cards.size();
      suit_sizes.push_back(sz);
      suit_points_1to4.push_back(calc_suit_points_1to4(cards, sz));
      suit_points_5to7.push_back(calc_suit_points_5to7(sz));
      suit_is_stopped.push_back(calc_suit_is_stopped(cards, sz));
    }

    int total_points_1to4 = 0;
    int total_points_5to7 = 0;
    bool is_all_stopped = true;
    for (int i = 0; i < 4; ++i) {
      total_points_1to4 += suit_points_1to4[i];
      total_points_5to7 += suit_points_5to7[i];
      is_all_stopped = is_all_stopped && suit_is_stopped[i];
    }

    if (total_points_1to4 + total_points_5to7 < 14) {
      cout << "PASS\n";
      continue;
    }

    cout << "BID ";
    if (total_points_1to4 >= 16 && is_all_stopped) {
      cout << "NO-TRUMP";
    } else {
      int suit = distance(suit_sizes.begin(),
                          max_element(suit_sizes.begin(), suit_sizes.end()));
      switch (suit) {
        case 0:
          cout << 'S';
          break;
        case 1:
          cout << 'H';
          break;
        case 2:
          cout << 'D';
          break;
        case 3:
          cout << 'C';
          break;
      }
    }
    cout << '\n';
  }
}
