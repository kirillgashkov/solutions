#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>


void input_grid(vvi& grid) {
    grid.reserve(3);

    for (int i = 0; i < 3; ++i) {
        vi row;
        row.reserve(3);

        for (int j = 0; j < 3; ++j) {
            char c;
            cin >> c;
            row.push_back(c - '0');
        }

        grid.push_back(row);
    }
}


vvi make_transformed(vvi& grid) {
    vvi out(grid);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            out[i][j] = 0;

            vi adj_i_list = {i - 1, i, i + 1, i};
            vi adj_j_list = {j, j - 1, j, j + 1};

            for (int k = 0; k < 4; ++k) {
                int adj_i = adj_i_list[k];
                int adj_j = adj_j_list[k];

                if (adj_i < 0 or adj_i > 2) continue;
                if (adj_j < 0 or adj_j > 2) continue;

                out[i][j] += grid[adj_i][adj_j];
            }

            out[i][j] %= 2;
        }
    }

    return out;
}


int calc_seed(vvi& grid) {
    bitset<9> seed;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            seed[i * 3 + j] = grid[i][j];
        }
    }

    return int(seed.to_ullong());
}


int main() {
    int cases_n;
    cin >> cases_n;

    for (int case_i = 0; case_i < cases_n; ++case_i) {
        vvi grid;
        input_grid(grid);

        unordered_map<int, int> when_for_what_met_seeds;

        int i = 0;
        when_for_what_met_seeds.emplace(calc_seed(grid), 0);

        int loop_seed;
        while (true) {
            grid = make_transformed(grid);
            int seed = calc_seed(grid);

            if (when_for_what_met_seeds.find(seed) != when_for_what_met_seeds.end()) {
                loop_seed = seed;
                break;
            }

            ++i;
            when_for_what_met_seeds.emplace(seed, i);
        }

        cout << when_for_what_met_seeds[loop_seed] - 1 << '\n';
    }
}
