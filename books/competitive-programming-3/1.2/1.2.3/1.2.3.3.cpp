#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define INF 1000000000;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(int argc, char const* argv[]) {
  ifstream fin("input.txt");
  string date;
  while (getline(fin, date)) {
    struct tm raw_date;
    strptime(date.c_str(), "%d %B %Y", &raw_date);
    const int wday = raw_date.tm_wday;
    switch (wday) {
      case 0:
        cout << "Sunday";
        break;
      case 1:
        cout << "Monday";
        break;
      case 2:
        cout << "Tuesday";
        break;
      case 3:
        cout << "Wednesday";
        break;
      case 4:
        cout << "Thursday";
        break;
      case 5:
        cout << "Friday";
        break;
      case 6:
        cout << "Saturday";
        break;
      default:
        cout << "?";
        break;
    }
    cout << '\n';
  }
  return 0;
}
