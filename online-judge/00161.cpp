#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define vi vector<int>
#define vf vector<float>

// this is the exact epsilon that allows us to correctly approximate the sines
#define EPSILON (1.0E-3)


void output_secs(int secs) {
    int mins = secs / 60 % 60;
    int hours = secs / 60 / 60;
    int secs60 = secs % 60;

    cout << '0' << hours << ':';

    if (mins / 10 == 0) {
        cout << '0';
    }

    cout << mins << ':';

    if (secs60 / 10 == 0) {
        cout << '0';
    }

    cout << secs60 << '\n';
}


int main() {
    while (true) {
        vi half_t_list;
        int half_t_count;

        int half_t_in;
        cin >> half_t_in;
        while (half_t_in != 0) {
            half_t_list.push_back(half_t_in);
            cin >> half_t_in;
        }
        half_t_count = half_t_list.size();

        if (half_t_list.empty()) {
            break;
        }


        vf sin_parameters;
        sin_parameters.reserve(half_t_count);

        for (auto& half_t : half_t_list) {
            sin_parameters.push_back(M_PI / half_t);
        }


        int min_half_t = 91;
        for (auto& half_t : half_t_list) {
            if (half_t < min_half_t) {
                min_half_t = half_t;
            }
        }
        int min_i_when_orange = min_half_t - 5;


        int found_i = -1;
        for (int i = min_i_when_orange; i <= 5 * 60 * 60; ++i) {
            bool is_all_green = true;

            for (auto& par : sin_parameters) {
                float k1 = sin(par * float(i));
                float k2 = sin(par * float(i + 5));

                // approximate
                if (fabs(k1) < EPSILON) k1 = 0;
                if (fabs(k2) < EPSILON) k2 = 0;

                // green or orange, then green
                if (not (k1 >= 0 and k2 > 0)) {
                    is_all_green = false;
                    break;
                }
            }

            if (is_all_green) {
                found_i = i;
                break;
            }
        }

        if (found_i != -1) {
            output_secs(found_i);
        } else {
            cout << "Signals fail to synchronise in 5 hours\n";
        }
    }
}
