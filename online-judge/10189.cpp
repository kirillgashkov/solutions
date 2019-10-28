#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>


void handle_mine(int& i, int& j, vvi& field, int& n, int& m) {
    vi i_list = {i-1, i, i+1, i-1, i+1, i-1, i, i+1};
    vi j_list = {j-1, j-1, j-1, j, j, j+1, j+1, j+1};

    for (int l = 0; l < 8; ++l) {
        int t_i = i_list[l];
        int t_j = j_list[l];

        if (t_i < 0 or t_i >= n) continue;
        if (t_j < 0 or t_j >= m) continue;

        if (field[t_i][t_j] != -1) {
            ++field[t_i][t_j];
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int case_count = 0;

    while (true) {
        ++case_count;

        int n, m;
        cin >> n >> m;

        if (n == 0 and m == 0) {
            break;
        }
        if (case_count != 1) cout << '\n';
        cout << "Field #" << case_count << ":\n";

        vvi field;
        for (int i = 0; i < n; ++i) {
            vi row;

            for (int j = 0; j < m; ++j) {
                char el;

                cin >> el;

                if (el == '*') {
                    row.push_back(-1);
                } else {
                    row.push_back(0);
                }
            }

            field.push_back(row);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (field[i][j] == -1) {
                    handle_mine(i, j, field, n, m);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (field[i][j] == -1) {
                    cout << '*';
                } else {
                    cout << field[i][j];
                }
            }
            cout << '\n';
        }
    }
}
