#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int, int>

ii get_forward_ij(int i, int j, int direction) {
  switch (direction) {
    case 1:
      return {i, j + 1};
    case 2:
      return {i - 1, j};
    case 3:
      return {i, j - 1};
    case 4:
      return {i + 1, j};
    default:
      return {-1, -1};
  }
}

int get_turned_left_direction(int direction, int n_times) {
  return (direction - 1 + n_times) % 4 + 1;
}

struct Bot {
  int i;
  int j;
  int target_i;
  int target_j;
  int direction;  // 1->e 2->n 3->w 4->s

  Bot(int i, int j, int direction) {
    this->i = i;
    this->j = j;
    this->target_i = i;
    this->target_j = j;
    this->direction = direction;
  }

  bool did_return() { return i == target_i and j == target_j; }

  // returns move type
  int move(vvi& field) {
    ii forward_ij = get_forward_ij(i, j, direction);

    if (field[forward_ij.first][forward_ij.second] == -1) {
      direction = get_turned_left_direction(direction, 1);
      return 1;
    }

    i = forward_ij.first;
    j = forward_ij.second;

    if (did_return()) {
      return 12;  // ten means done
    }

    field[i][j] += 1;

    int turned_right_direction = get_turned_left_direction(direction, 3);
    ii forward_right_ij = get_forward_ij(i, j, turned_right_direction);

    if (field[forward_right_ij.first][forward_right_ij.second] == -1) {
      return 2;
    }

    i = forward_right_ij.first;
    j = forward_right_ij.second;
    direction = turned_right_direction;

    if (did_return()) {
      return 13;  // ten means done
    }

    field[i][j] += 1;

    return 3;
  }
};

int main() {
  while (true) {
    int n, m;
    cin >> n >> m;

    if (n == 0) {
      break;
    }

    // we make a field (n+2)x(m+2) cuz we want to include the outer walls
    // we also override all "1"s to "-1"s cuz we gonna use the same field
    // variable for counting the visits
    vvi field;
    field.resize(n + 2);

    // outer walls
    vi wall_row;
    wall_row.resize(m + 2);
    fill(wall_row.begin(), wall_row.end(), -1);
    field[0] = wall_row;
    field[n + 1] = wall_row;

    for (int i = 1; i <= n; ++i) {
      vi row;
      row.resize(m + 2);

      // outer walls
      row[0] = -1;
      row[m + 1] = -1;

      for (int j = 1; j <= m; ++j) {
        char square;
        cin >> square;
        row[j] = square == '0' ? 0 : -1;
      }

      field[i] = row;
    }

    Bot bot(n, 1, 1);  // east
    field[n][1] += 1;  // it gets here anyways and it is not counted

    do {
    move_without_check:;
      int move_type = bot.move(field);
      if (move_type == 1)
        goto move_without_check;
    } while (not bot.did_return());

    int zero_count = 0;
    int one_count = 0;
    int two_count = 0;
    int three_count = 0;
    int four_count = 0;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        switch (field[i][j]) {
          case 0:
            ++zero_count;
            break;
          case 1:
            ++one_count;
            break;
          case 2:
            ++two_count;
            break;
          case 3:
            ++three_count;
            break;
          case 4:
            ++four_count;
            break;
          default:
            break;
        }
      }
    }

    printf("% 3d% 3d% 3d% 3d% 3d\n", zero_count, one_count, two_count,
           three_count, four_count);
  }
}
