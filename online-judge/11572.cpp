#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i_t = 0; i_t < t; ++i_t) {
    int n;
    cin >> n;

    unordered_map<int, int> last_snowflake_indices;

    int max_length = -1;
    int current_start = 0;
    int current_index = 0;

    for (int i = 0; i < n; ++i) {
      int snowflake;
      cin >> snowflake;

      if (last_snowflake_indices.find(snowflake) ==
          last_snowflake_indices.end()) {
        last_snowflake_indices[snowflake] = current_index;
      } else if (last_snowflake_indices[snowflake] >= current_start) {
        max_length = max(max_length, current_index - current_start);
        current_start = last_snowflake_indices[snowflake] + 1;
        last_snowflake_indices[snowflake] = current_index;
      } else {
        last_snowflake_indices[snowflake] = current_index;
      }

      current_index += 1;
    }
    max_length = max(max_length, current_index - current_start);

    cout << max_length << '\n';
  }
}
