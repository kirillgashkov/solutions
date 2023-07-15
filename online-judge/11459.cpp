#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>

int main() {
  int test_cases;
  cin >> test_cases;

  for (int test_case = 0; test_case < test_cases; ++test_case) {
    int players_count, movers_count, rolls_count;
    cin >> players_count >> movers_count >> rolls_count;

    vi board;
    board.reserve(100);

    for (int i = 0; i < 100; ++i) {
      board.push_back(-1);
    }

    for (int i = 0; i < movers_count; ++i) {
      int from, to;
      cin >> from >> to;
      // translating indices
      board[from - 1] = to - 1;
    }

    vi die_rolls;

    for (int i = 0; i < rolls_count; ++i) {
      int die_roll;
      cin >> die_roll;
      die_rolls.push_back(die_roll);
    }

    vi player_positions;
    player_positions.resize(players_count);
    fill(player_positions.begin(), player_positions.end(), 0);

    int last_die_roll_i = -1;

    while (true) {
      for (int i = 0; i < players_count; ++i) {
        ++last_die_roll_i;
        if (last_die_roll_i >= die_rolls.size()) {
          // out of die rolls
          goto out;
        }

        int new_pos = player_positions[i] + die_rolls[last_die_roll_i];

        int square_target = board[new_pos];
        if (square_target != -1) {
          // ladder or square
          player_positions[i] = square_target;
        } else {
          // all right
          player_positions[i] = new_pos;
        }

        if (player_positions[i] >= 99) {
          // the player won
          player_positions[i] = 99;
          goto out;
        }
      }
    }
  out:

    for (int i = 0; i < players_count; ++i) {
      cout << "Position of player " << i + 1 << " is "
           << player_positions[i] + 1 << ".\n";
    }
  }
}
