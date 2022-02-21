#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vi a;
        for (int i = 0; i < n; i++) {
            int number;
            cin >> number;
            a.push_back(number);
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                a[j] = a[j] - (a[j] & a[i]);
            }
        }

        long long s = 0;
        for (int i = 0; i < n; i++) {
            s += a[i];
        }

        cout << s << '\n';
    }

    return 0;
}
