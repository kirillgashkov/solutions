#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define ii pair<int, int>
#define vii vector<ii>
#define vi vector<int>

const int DUMMY_ROLL = 1000;
const int STRIKE_ROLL = -2;
const int SPARE_ROLL = -1;

int calc_spare_bonus(int i, vii& frames) {
  if (i >= 9) {
    return 0;
  }

  ii next_frame = frames[i + 1];

  switch (next_frame.first) {
    case STRIKE_ROLL:
      return 10;
    default:
      return next_frame.first;
  }
}

int calc_strike_bonus(int i, vii& frames) {
  if (i >= 9) {
    return 0;
  }

  int bonus = 0;

  ii next_frame = frames[i + 1];
  ii next_next_frame = frames[i + 2];

  switch (next_frame.second) {
    case DUMMY_ROLL:
      bonus += 10;

      if (next_next_frame.first == STRIKE_ROLL) {
        bonus += 10;
      } else {
        bonus += next_next_frame.first;
      }
      break;
    case SPARE_ROLL:
      bonus += 10;
      break;
    default:
      bonus += next_frame.first + next_frame.second;
      break;
  }

  return bonus;
}

int main() {
  while (true) {
    string rolls_str;
    getline(cin, rolls_str);

    if (rolls_str == "Game Over") {
      break;
    }

    istringstream rolls_stream(rolls_str);

    vi rolls;

    char roll_c;
    while (rolls_stream >> roll_c) {
      switch (roll_c) {
        case 'X':
          rolls.push_back(STRIKE_ROLL);
          break;
        case '/':
          rolls.push_back(SPARE_ROLL);
          break;
        default:
          rolls.push_back(int(roll_c - '0'));
          break;
      }
    }

    vii frames;

    int prev_roll = DUMMY_ROLL;
    for (auto& roll : rolls) {
      switch (roll) {
        case STRIKE_ROLL:
          frames.emplace_back(STRIKE_ROLL, DUMMY_ROLL);
          prev_roll = DUMMY_ROLL;
          break;
        case SPARE_ROLL:
          frames.emplace_back(prev_roll, SPARE_ROLL);
          prev_roll = DUMMY_ROLL;
          break;
        default:
          if (prev_roll != DUMMY_ROLL) {
            frames.emplace_back(prev_roll, roll);
            prev_roll = DUMMY_ROLL;
          } else {
            prev_roll = roll;
          }
          break;
      }
    }
    if (prev_roll != DUMMY_ROLL) {
      frames.emplace_back(prev_roll, 0);
    }

    int score = 0;

    for (int i = 0; i < int(frames.size()); ++i) {
      ii frame = frames[i];

      switch (frame.second) {
        case DUMMY_ROLL:
          score += 10;
          score += calc_strike_bonus(i, frames);
          break;
        case SPARE_ROLL:
          // spare
          score += 10;
          score += calc_spare_bonus(i, frames);
          break;
        default:
          // regular
          score += frame.first;
          score += frame.second;
          break;
      }
    }

    cout << score << '\n';
  }
}
