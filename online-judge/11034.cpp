#include <iostream>
#include <deque>
using namespace std;


int main() {
    int t;
    cin >> t;

    for (int i_t = 0; i_t < t; ++i_t) {
        int ferry_l_in_meters, m;
        cin >> ferry_l_in_meters >> m;
        int ferry_l = ferry_l_in_meters * 100;

        deque<int> left;
        deque<int> right;

        for (int i = 0; i < m; ++i) {
            int l;
            string side;
            cin >> l >> side;

            bool is_left = side[0] == 'l';

            if (is_left) {
                left.push_back(l);
            } else {
                right.push_back(l);
            }
        }


        int cross_k = 0;
        bool ferry_is_left = true;

        while (!left.empty() or !right.empty()) {
            int unused_ferry_l = ferry_l;

            if (ferry_is_left) {
                while (!left.empty() and unused_ferry_l - left.front() >= 0) {
                    unused_ferry_l -= left.front();
                    left.pop_front();
                }
            } else {
                while (!right.empty() and unused_ferry_l - right.front() >= 0) {
                    unused_ferry_l -= right.front();
                    right.pop_front();
                }
            }

            ++cross_k;
            ferry_is_left = !ferry_is_left;
        }


        cout << cross_k << '\n';
    }
}
