#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main() {
    int t;
    cin >> t;

    for (int i_t = 0; i_t < t; ++i_t) {
        if (i_t != 0) {
            cout << '\n';
        }

        int b, sg, sb;
        cin >> b >> sg >> sb;

        priority_queue<int> greens;

        for (int i = 0; i < sg; ++i) {
            int power;
            cin >> power;
            greens.push(power);
        }

        priority_queue<int> blues;

        for (int i = 0; i < sb; ++i) {
            int power;
            cin >> power;
            blues.push(power);
        }


        while (!greens.empty() and !blues.empty()) {
            int k = min(min((int)greens.size(), (int)blues.size()), b);

            vector<int> greens_buffer;
            vector<int> blues_buffer;

            for (int i = 0; i < k; ++i) {
                int green = greens.top();
                int blue = blues.top();

                greens.pop();
                blues.pop();


                int result = green - blue;

                if (result > 0) {
                    // green won
                    greens_buffer.push_back(result);
                } else if (result < 0) {
                    // blue won
                    blues_buffer.push_back(-result);
                } // else tie
            }

            for (auto& green_from_buffer : greens_buffer) {
                greens.push(green_from_buffer);
            }

            for (auto& blue_from_buffer : blues_buffer) {
                blues.push(blue_from_buffer);
            }
        }


        if (!greens.empty()) {
            cout << "green wins\n";
            while (!greens.empty()) {
                cout << greens.top() << '\n';
                greens.pop();
            }
        } else if (!blues.empty()) {
            cout << "blue wins\n";
            while (!blues.empty()) {
                cout << blues.top() << '\n';
                blues.pop();
            }
        } else {
            cout << "green and blue died\n";
        }
    }
}
