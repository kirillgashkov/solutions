#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000000;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(int argc, char const* argv[]) {
  FILE* fin = fopen("input.txt", "r");
  double number;
  while (fscanf(fin, "%lf,", &number) != EOF) {
    printf("%7.3f\n", number);
  }
  return 0;
}
