#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#define vc vector<char>
#define vvc vector<vc>

// grid

void init_grid(vvc& grid) {
  grid.reserve(60);

  for (int i = 0; i < 60; ++i) {
    vc row;
    row.resize(60);

    fill(row.begin(), row.end(), '.');

    grid.push_back(row);
  }
}

void reset_grid(vvc& grid) {
  for (int i = 0; i < 60; ++i) {
    for (int j = 0; j < 60; ++j) {
      grid[i][j] = '.';
    }
  }
}

// render

bool is_valid_i(int i) {
  return i >= 0 and i <= 59;
}

void insert_c1(vvc& grid, int row_i, int col_i, char c) {
  if (not(is_valid_i(row_i) and is_valid_i(col_i)))
    return;
  if (c == ' ')
    return;

  grid[row_i][col_i] = c;
}

unordered_map<char, vvc> c2_reprs = {{'A',
                                      {{'.', '*', '*', '*', '.', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '*', '*', '*', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'}}},
                                     {'B',
                                      {{'*', '*', '*', '*', '.', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '*', '*', '*', '.', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '*', '*', '*', '.', '.'}}},
                                     {'C',
                                      {{'.', '*', '*', '*', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '.', '.', '.'},
                                       {'*', '.', '.', '.', '.', '.'},
                                       {'.', '*', '*', '*', '*', '.'}}},
                                     {'D',
                                      {{'*', '*', '*', '*', '.', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '*', '*', '*', '.', '.'}}},
                                     {'E',
                                      {{'*', '*', '*', '*', '*', '.'},
                                       {'*', '.', '.', '.', '.', '.'},
                                       {'*', '*', '*', '.', '.', '.'},
                                       {'*', '.', '.', '.', '.', '.'},
                                       {'*', '*', '*', '*', '*', '.'}}},
                                     {'F',
                                      {{'*', '*', '*', '*', '*', '.'},
                                       {'*', '.', '.', '.', '.', '.'},
                                       {'*', '*', '*', '.', '.', '.'},
                                       {'*', '.', '.', '.', '.', '.'},
                                       {'*', '.', '.', '.', '.', '.'}}},
                                     {'G',
                                      {{'.', '*', '*', '*', '*', '.'},
                                       {'*', '.', '.', '.', '.', '.'},
                                       {'*', '.', '.', '*', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'.', '*', '*', '*', '.', '.'}}},
                                     {'H',
                                      {{'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '*', '*', '*', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'}}},
                                     {'I',
                                      {{'*', '*', '*', '*', '*', '.'},
                                       {'.', '.', '*', '.', '.', '.'},
                                       {'.', '.', '*', '.', '.', '.'},
                                       {'.', '.', '*', '.', '.', '.'},
                                       {'*', '*', '*', '*', '*', '.'}}},
                                     {'J',
                                      {{'.', '.', '*', '*', '*', '.'},
                                       {'.', '.', '.', '*', '.', '.'},
                                       {'.', '.', '.', '*', '.', '.'},
                                       {'*', '.', '.', '*', '.', '.'},
                                       {'.', '*', '*', '.', '.', '.'}}},
                                     {'K',
                                      {{'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '*', '.', '.'},
                                       {'*', '*', '*', '.', '.', '.'},
                                       {'*', '.', '.', '*', '.', '.'},
                                       {'*', '.', '.', '.', '*', '.'}}},
                                     {'L',
                                      {{'*', '.', '.', '.', '.', '.'},
                                       {'*', '.', '.', '.', '.', '.'},
                                       {'*', '.', '.', '.', '.', '.'},
                                       {'*', '.', '.', '.', '.', '.'},
                                       {'*', '*', '*', '*', '*', '.'}}},
                                     {'M',
                                      {{'*', '.', '.', '.', '*', '.'},
                                       {'*', '*', '.', '*', '*', '.'},
                                       {'*', '.', '*', '.', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'}}},
                                     {'N',
                                      {{'*', '.', '.', '.', '*', '.'},
                                       {'*', '*', '.', '.', '*', '.'},
                                       {'*', '.', '*', '.', '*', '.'},
                                       {'*', '.', '.', '*', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'}}},
                                     {'O',
                                      {{'.', '*', '*', '*', '.', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'.', '*', '*', '*', '.', '.'}}},
                                     {'P',
                                      {{'*', '*', '*', '*', '.', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '*', '*', '*', '.', '.'},
                                       {'*', '.', '.', '.', '.', '.'},
                                       {'*', '.', '.', '.', '.', '.'}}},
                                     {'Q',
                                      {{'.', '*', '*', '*', '.', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '*', '*', '.'},
                                       {'.', '*', '*', '*', '*', '.'}}},
                                     {'R',
                                      {{'*', '*', '*', '*', '.', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '*', '*', '*', '.', '.'},
                                       {'*', '.', '.', '*', '.', '.'},
                                       {'*', '.', '.', '.', '*', '.'}}},
                                     {'S',
                                      {{'.', '*', '*', '*', '*', '.'},
                                       {'*', '.', '.', '.', '.', '.'},
                                       {'.', '*', '*', '*', '.', '.'},
                                       {'.', '.', '.', '.', '*', '.'},
                                       {'*', '*', '*', '*', '.', '.'}}},
                                     {'T',
                                      {{'*', '*', '*', '*', '*', '.'},
                                       {'*', '.', '*', '.', '*', '.'},
                                       {'.', '.', '*', '.', '.', '.'},
                                       {'.', '.', '*', '.', '.', '.'},
                                       {'.', '*', '*', '*', '.', '.'}}},
                                     {'U',
                                      {{'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'.', '*', '*', '*', '.', '.'}}},
                                     {'V',
                                      {{'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'.', '*', '.', '*', '.', '.'},
                                       {'.', '*', '.', '*', '.', '.'},
                                       {'.', '.', '*', '.', '.', '.'}}},
                                     {'W',
                                      {{'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'},
                                       {'*', '.', '*', '.', '*', '.'},
                                       {'*', '*', '.', '*', '*', '.'},
                                       {'*', '.', '.', '.', '*', '.'}}},
                                     {'X',
                                      {{'*', '.', '.', '.', '*', '.'},
                                       {'.', '*', '.', '*', '.', '.'},
                                       {'.', '.', '*', '.', '.', '.'},
                                       {'.', '*', '.', '*', '.', '.'},
                                       {'*', '.', '.', '.', '*', '.'}}},
                                     {'Y',
                                      {{'*', '.', '.', '.', '*', '.'},
                                       {'.', '*', '.', '*', '.', '.'},
                                       {'.', '.', '*', '.', '.', '.'},
                                       {'.', '.', '*', '.', '.', '.'},
                                       {'.', '.', '*', '.', '.', '.'}}},
                                     {'Z',
                                      {{'*', '*', '*', '*', '*', '.'},
                                       {'.', '.', '.', '*', '.', '.'},
                                       {'.', '.', '*', '.', '.', '.'},
                                       {'.', '*', '.', '.', '.', '.'},
                                       {'*', '*', '*', '*', '*', '.'}}},
                                     {' ',
                                      {{'.', '.', '.', '.', '.', '.'},
                                       {'.', '.', '.', '.', '.', '.'},
                                       {'.', '.', '.', '.', '.', '.'},
                                       {'.', '.', '.', '.', '.', '.'},
                                       {'.', '.', '.', '.', '.', '.'}}}};

void insert_c2(vvc& grid, int row_i, int col_i, char c) {
  vvc& c_grid = c2_reprs[c];

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 6; ++j) {
      if (c_grid[i][j] == '.') {
        continue;
      }

      int row_idx = row_i + i;
      int col_idx = col_i + j;

      if (not(is_valid_i(row_idx) and is_valid_i(col_idx)))
        continue;

      grid[row_idx][col_idx] = c_grid[i][j];
    }
  }
}

void insert_char(vvc& grid, int font, int row_i, int col_i, char c) {
  // assumes left top notation

  switch (font) {
    case 1:
      insert_c1(grid, row_i, col_i, c);
      break;
    case 5:
      insert_c2(grid, row_i, col_i, c);
      break;
    default:
      break;
  }
}

void insert_string(vvc& grid, int font, int row, int col, string& str) {
  // assumes left top notation

  int font_width = font == 1 ? 1 : 6;

  int row_i = row - 1;
  int col_i = col - 1;

  for (auto& c : str) {
    insert_char(grid, font, row_i, col_i, c);
    col_i += font_width;
  }
}

// commands

void exec_place_command(vvc& grid, string& line) {
  int font, row, col;
  char c_str[256];

  sscanf(line.c_str(), ".P C%i %i %i |%[^|]", &font, &row, &col, c_str);

  string str(c_str);

  insert_string(grid, font, row, col, str);
}

void exec_left_command(vvc& grid, string& line) {
  int font, row;
  char c_str[256];

  sscanf(line.c_str(), ".L C%d %d |%[^|]", &font, &row, c_str);

  string str(c_str);

  insert_string(grid, font, row, 1, str);
}

void exec_right_command(vvc& grid, string& line) {
  int font, row;
  char c_str[256];

  sscanf(line.c_str(), ".R C%i %i |%[^|]", &font, &row, c_str);

  string str(c_str);

  int font_width = font == 1 ? 1 : 6;
  int width = font_width * int(str.size());
  insert_string(grid, font, row, 60 - width + 1, str);
}

void exec_center_command(vvc& grid, string& line) {
  int font, row;
  char c_str[256];

  sscanf(line.c_str(), ".C C%i %i |%[^|]", &font, &row, c_str);

  string str(c_str);

  int font_width = font == 1 ? 1 : 6;
  int width = font_width * int(str.size());
  insert_string(grid, font, row, 30 - (width / 2) + 1, str);
}

void exec_eop_command(vvc& grid, string& line) {
  // .EOP
  for (auto& row : grid) {
    for (auto& c : row) {
      putchar(c);
    }
    putchar('\n');
  }

  putchar('\n');
  for (int i = 0; i < 60; ++i) {
    putchar('-');
  }
  putchar('\n');
  putchar('\n');
}

int main() {
  vvc grid;
  init_grid(grid);

  string command_line;
  while (getline(cin >> ws, command_line)) {
    char command = command_line[1];

    switch (command) {
      case 'P':
        exec_place_command(grid, command_line);
        break;
      case 'L':
        exec_left_command(grid, command_line);
        break;
      case 'R':
        exec_right_command(grid, command_line);
        break;
      case 'C':
        exec_center_command(grid, command_line);
        break;
      case 'E':
        exec_eop_command(grid, command_line);
        reset_grid(grid);
        break;
      default:
        break;
    }
  }
}
