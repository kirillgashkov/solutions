#include <iostream>
#include <vector>
#include <sstream>
#include <bitset>
using namespace std;

#define vi vector<int>


int main() {
    string case_line;

    while (getline(cin >> ws, case_line)) {
        istringstream case_stream(case_line);

        int n;
        case_stream >> n;

        vi a;
        a.resize(n);

        for (int i = 0; i < n; ++i) {
            case_stream >> a[i];
        }


        bitset<2999> jolly;
        int required_jolly_count = n - 1;

        for (int i = 0; i < n - 1; ++i) {
            int diff = abs(a[i] - a[i + 1]);

            if (diff > required_jolly_count or diff == 0) continue;

            jolly[diff - 1] = true;
        }


        if (jolly.count() == required_jolly_count) {
            cout << "Jolly\n";
        } else {
            cout << "Not jolly\n";
        }
    }
}
