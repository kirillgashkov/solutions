#include <cmath>
#include <iostream>
using namespace std;

void output_coordinates(int x, int y) {
  cout << "Line = " << x << ", column = " << y << ".\n";
}

int main() {
  while (true) {
    int n, p;
    cin >> n >> p;

    if (n == 0)
      break;

    int center_idx = n / 2 + 1;

    // edge case
    if (p == 1) {
      output_coordinates(center_idx, center_idx);
      continue;
    }

    int spiral = ceil(sqrt(p));
    spiral += spiral % 2 == 0 ? 1 : 0;

    int first_spiral_p = int(pow(spiral - 2, 2)) + 1;
    int last_spiral_p = int(pow(spiral, 2));
    int spiral_p_count = last_spiral_p - first_spiral_p + 1;
    int spiral_p_count_per_chunk = spiral_p_count / 4;

    int spiral_offset_from_center = spiral / 2;
    int spiral_offset_from_edge = (n - spiral) / 2;

    // p's position, chunk, chunk position in spiral
    int pos = p - first_spiral_p;
    int chunk = pos / spiral_p_count_per_chunk;
    int chunk_pos = pos % spiral_p_count_per_chunk;

    int x;
    int y;
    switch (chunk) {
      case 0:
        // top
        x = center_idx + spiral_offset_from_center;
        y = n - 1 - spiral_offset_from_edge - chunk_pos;
        break;
      case 1:
        // left
        x = n - 1 - spiral_offset_from_edge - chunk_pos;
        y = center_idx - spiral_offset_from_center;
        break;
      case 2:
        // bottom
        x = center_idx - spiral_offset_from_center;
        y = 2 + spiral_offset_from_edge + chunk_pos;
        break;
      case 3:
        // right
        x = 2 + spiral_offset_from_edge + chunk_pos;
        y = center_idx + spiral_offset_from_center;
        break;
      default:
        x = -1;
        y = -1;
        break;
    }

    output_coordinates(x, y);
  }
}
