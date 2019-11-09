#include <iostream>
#include <bitset>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases_n;
    cin >> cases_n;

    for (int case_i = 0; case_i < cases_n; ++case_i) {
        int n, k;
        cin >> n >> k;

        bitset<30> number(0);

        for (int i = 0; i < n; ++i) {
            number[i] = ((k + (1 << i)) >> (i + 1)) & 1;
        }

        cout << number.to_ulong() << '\n';
    }
}
