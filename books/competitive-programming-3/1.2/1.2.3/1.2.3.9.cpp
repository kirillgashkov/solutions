#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#define INF 1000000000;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

string ultos(unsigned long value, int base = 10) {
  string output;
  do {
    char digit = value % base;
    if (digit < 10) {
      digit += '0';
    } else {
      digit = digit + 'A' - 10;
    }
    output += digit;
    value /= base;
  } while (value > 0);
  reverse(output.begin(), output.end());
  return output;
}

int main(int argc, char const* argv[]) {
  ifstream fin("input.txt");

  string num_x;
  int base_x;
  int base_y;
  while (fin >> num_x >> base_x >> base_y) {
    int num = stoi(num_x, 0, base_x);
    string num_y = ultos(num, base_y);
    cout << num_y << '\n';
  }

  return 0;
}
