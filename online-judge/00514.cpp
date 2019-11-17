#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

#define vi vector<int>


int main() {
    bool is_first_case = true;

    while (true) {
        if (is_first_case) {
            is_first_case = false;
        } else {
            cout << '\n';
        }


        int n;
        cin >> n;

        if (n == 0) break;


        vi in_coaches;
        in_coaches.reserve(n);

        for (int i = 1; i <= n; ++i) {
            in_coaches.push_back(i);
        }


        while (true) {
            string out_coaches_string;
            getline(cin >> ws, out_coaches_string);

            if (out_coaches_string == "0") break;

            istringstream out_coaches_stream(out_coaches_string);


            vi out_coaches;
            out_coaches.resize(n);

            for (int i = 0; i < n; ++i) {
                out_coaches_stream >> out_coaches[i];
            }


            vi station_coaches;


            int in_coach_i = 0;
            int out_coach_i = 0;

            int last_coach_i = n - 1;
            

            while (true) {
                if (out_coach_i > last_coach_i) {
                    cout << "Yes\n";
                    break;
                }

                if (station_coaches.empty() or station_coaches.back() != out_coaches[out_coach_i]) {
                    if (in_coach_i > last_coach_i) {
                        // we gotta read coaches but we can't
                        cout << "No\n";
                        break;
                    }

                    int coach = in_coaches[in_coach_i];
                    station_coaches.push_back(coach);
                    in_coach_i += 1;
                } else {
                    // means station has our coach and we gotta send it
                    station_coaches.pop_back();
                    out_coach_i += 1;
                }
            }
        }
    }
}
