#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define us_int unsigned short

us_int battle(us_int a, us_int b) {
    us_int ab = a | b;

    switch (ab) {
        case 1: // 001 RR
        case 5: // 101 SR
            return 1; // 001 R
        case 2: // 010 PP
        case 3: // 011 PR
            return 2; // P
        case 4: // 100 SS
        case 6: // 110 SP
            return 4; // S
        default:
            return 0;
    }
}


vvi deep_copy_field(vvi& field, int n, int m) {
    vvi new_field;
    new_field.resize(n);

    for (int i = 0; i < n; ++i) {
        vi new_row;
        new_row.resize(m);

        for (int j = 0; j < m; ++j) {
            new_row[j] = field[i][j];
        }

        new_field[i] = new_row;
    }

    return new_field;
}


void battle_neighbors(int i, int j, vvi& field, vvi& old_field, int n, int m) {
    us_int attacker = old_field[i][j];

    vi i_list = {i - 1, i, i + 1, i};
    vi j_list = {j, j + 1, j, j - 1};

    for (int l = 0; l < 4; ++l) {
        int b_i = i_list[l];
        int b_j = j_list[l];

        if (b_i < 0 or b_i >= n or b_j < 0 or b_j >= m) {
            continue;
        }

        us_int defender = old_field[b_i][b_j];
        us_int winner = battle(attacker, defender);
        
        if (winner == attacker and attacker != defender) {
            field[b_i][b_j] = winner;
        }
    }
}


void battle_one_day(vvi& field, int n, int m) {
    vvi old_field = deep_copy_field(field, n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            battle_neighbors(i, j, field, old_field, n, m);
        }
    }
}


int main() {
    int case_count;
    cin >> case_count;

    for (int cs = 0; cs < case_count; ++cs) {
        if (cs != 0) {
            cout << '\n';
        }

        int n, m, d;
        cin >> n >> m >> d;

        vvi field;
        field.resize(n);

        for (int i = 0; i < n; ++i) {
            vi row;
            row.resize(m);

            for (int j = 0; j < m; ++j) {
                char creature;

                cin >> creature;

                switch (creature) {
                    case 'R':
                        row[j] = 1; // 001
                        break;
                    case 'P':
                        row[j] = 2; // 010
                        break;
                    case 'S':
                        row[j] = 4; // 100
                        break;
                    default:
                        row[j] = 0;
                        break;
                }
            }

            field[i] = row;
        }


        for (int l = 0; l < d; ++l) {
            battle_one_day(field, n, m);
        }


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                switch (field[i][j]) {
                    case 1:
                        cout << 'R';
                        break;
                    case 2:
                        cout << 'P';
                        break;
                    case 4:
                        cout << 'S';
                        break;
                    default:
                        throw runtime_error("?");
                }
            }
            cout << '\n';
        }
    }

}
