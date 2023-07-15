#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define sc unordered_set<char>

const string COIN_IDS = "ABCDEFGHIJKL";

struct Coin {
  bool can_be_heavy = true;
  bool can_be_light = true;
};

void read_balance(sc& balance) {
  string balance_s;
  cin >> balance_s;

  balance = sc(balance_s.begin(), balance_s.end());
}

void read_weighing_result(char& weighing_result) {
  string result;

  cin >> result;

  // e - even
  // u - up
  // d - down
  weighing_result = result[0];
}

void handle_weighing(unordered_map<char, Coin>& coins,
                     sc& left,
                     sc& right,
                     char& weighing_result) {
  sc met_coin_ids;
  for (auto& coin_id : left)
    met_coin_ids.insert(coin_id);
  for (auto& coin_id : right)
    met_coin_ids.insert(coin_id);

  switch (weighing_result) {
    case 'e':
      for (auto& coin_id : met_coin_ids) {
        Coin& coin = coins[coin_id];
        coin.can_be_heavy = false;
        coin.can_be_light = false;
      }
      break;
    case 'u':
      for (auto& coin_id : left) {
        Coin& coin = coins[coin_id];
        coin.can_be_light = false;
      }
      for (auto& coin_id : right) {
        Coin& coin = coins[coin_id];
        coin.can_be_heavy = false;
      }
      for (auto& coin_id : COIN_IDS) {
        if (met_coin_ids.find(coin_id) == met_coin_ids.end()) {
          Coin& coin = coins[coin_id];
          coin.can_be_heavy = false;
          coin.can_be_light = false;
        }
      }
      break;
    case 'd':
      for (auto& coin_id : left) {
        Coin& coin = coins[coin_id];
        coin.can_be_heavy = false;
      }
      for (auto& coin_id : right) {
        Coin& coin = coins[coin_id];
        coin.can_be_light = false;
      }
      for (auto& coin_id : COIN_IDS) {
        if (met_coin_ids.find(coin_id) == met_coin_ids.end()) {
          Coin& coin = coins[coin_id];
          coin.can_be_heavy = false;
          coin.can_be_light = false;
        }
      }
      break;
    default:
      break;
  }
}

int main() {
  int cases_n;
  cin >> cases_n;

  for (int case_i = 0; case_i < cases_n; ++case_i) {
    unordered_map<char, Coin> coins;

    for (auto& coin_id : COIN_IDS) {
      coins[coin_id] = Coin();
    }

    sc left;
    sc right;
    char weighing_result;  // e|u|d

    for (int i = 0; i < 3; ++i) {
      read_balance(left);
      read_balance(right);
      read_weighing_result(weighing_result);

      handle_weighing(coins, left, right, weighing_result);
    }

    for (auto& id_and_coin : coins) {
      Coin& coin = id_and_coin.second;
      char id = id_and_coin.first;

      if (coin.can_be_heavy) {
        cout << id << " is the counterfeit coin and it is heavy.\n";
        break;
      } else if (coin.can_be_light) {
        cout << id << " is the counterfeit coin and it is light.\n";
        break;
      }
    }
  }
}
