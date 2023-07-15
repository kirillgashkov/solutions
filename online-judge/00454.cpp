#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#define vs vector<string>

string get_normalized_line(string& line) {
  string normalized_line;

  for (auto& c : line) {
    if (c == ' ')
      continue;
    normalized_line.push_back(c);
  }

  sort(normalized_line.begin(), normalized_line.end());

  return normalized_line;
}

int main() {
  int case_n;
  cin >> case_n;

  for (int case_i = 0; case_i < case_n; ++case_i) {
    if (case_i != 0) {
      cout << '\n';
    }

    vs in_lines;

    string in_line;
    getline(cin >> ws, in_line);
    while (not in_line.empty()) {
      in_lines.push_back(in_line);
      getline(cin, in_line);
    }

    unordered_map<string, vs> lines_for_norms;

    for (auto& line : in_lines) {
      string norm = get_normalized_line(line);

      if (lines_for_norms.find(norm) == lines_for_norms.end()) {
        lines_for_norms[norm] = vector<string>();
      }

      lines_for_norms[norm].push_back(line);
    }

    vs out_lines;

    for (auto& norm_and_lines : lines_for_norms) {
      vs& lines = norm_and_lines.second;
      sort(lines.begin(), lines.end());
      int n = lines.size();

      if (n < 2)
        continue;

      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          string out_line = lines[i] + " = " + lines[j];
          out_lines.push_back(out_line);
        }
      }
    }

    sort(out_lines.begin(), out_lines.end());

    for (auto& line : out_lines) {
      cout << line << '\n';
    }
  }
}
