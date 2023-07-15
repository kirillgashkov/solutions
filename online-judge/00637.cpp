#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

void output_sheet_side(int sheet_i, string& side, int page_1, int page_2) {
  cout << "Sheet " << sheet_i + 1 << ", " << side << ": ";
  cout << (page_1 == -1 ? string("Blank") : to_string(page_1));
  cout << ", ";
  cout << (page_2 == -1 ? string("Blank") : to_string(page_2));
  cout << '\n';
}

int main() {
  while (true) {
    int pages_n;
    cin >> pages_n;
    if (pages_n == 0) {
      break;
    }

    cout << "Printing order for " << pages_n << " pages:\n";

    int sheets_n = ceil(pages_n / 4.0);
    int max_pages_n = sheets_n * 4;
    int max_inner_page = max_pages_n / 2;

    vvi sheets;
    sheets.reserve(sheets_n);
    for (int i = 0; i < sheets_n; ++i) {
      sheets.push_back({-1, -1, -1, -1});
    }

    for (int page = 1; page <= pages_n; ++page) {
      if (page <= max_inner_page) {
        // inner
        int sheet_i = (page - 1) / 2;

        if (page % 2 == 1) {
          // front 0 {1} | 2 3
          sheets[sheet_i][1] = page;
        } else {
          // back 0 1 | {2} 3
          sheets[sheet_i][2] = page;
        }
      } else {
        // outer
        int sheet_i = (sheets_n * 2 - 1) - (page - 1) / 2;

        if (page % 2 == 0) {
          // front {0} 1 | 2 3
          sheets[sheet_i][0] = page;
        } else {
          // back 0 1 | 2 {3}
          sheets[sheet_i][3] = page;
        }
      }
    }

    string front_side = "front";
    string back_side = "back ";
    for (int sheet_i = 0; sheet_i < sheets_n; ++sheet_i) {
      vi& sheet = sheets[sheet_i];

      if (sheet[0] != -1 or sheet[1] != -1) {
        output_sheet_side(sheet_i, front_side, sheet[0], sheet[1]);
      }
      if (sheet[2] != -1 or sheet[3] != -1) {
        output_sheet_side(sheet_i, back_side, sheet[2], sheet[3]);
      }
    }
  }
}
