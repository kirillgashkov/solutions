#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>


void output_vector_no_newline(vi& v) {
    if (v.empty()) {
        return;
    }

    cout << v[0];

    for (int i = 1; i < v.size(); ++i) {
        cout << ' ' << v[i];
    }
}


int main() {
    while (true) {
        int n, m;
        cin >> n >> m;

        if (!cin) break;


        vvi rows_nums;
        rows_nums.resize(m + 1); // there will be m rows 1-based

        vvi rows_idxs;
        rows_idxs.resize(m + 1); // there will be m rows 1-based


        for (int i = 1; i <= n; ++i) {
            int nums_k;
            cin >> nums_k;

            vi j_list;
            j_list.resize(nums_k);

            for (int num_i = 0; num_i < nums_k; ++num_i) {
                cin >> j_list[num_i];

                rows_idxs[j_list[num_i]].push_back(i);
            }

            for (int num_i = 0; num_i < nums_k; ++num_i) {
                int num;
                cin >> num;

                rows_nums[j_list[num_i]].push_back(num);
            }
        }


        cout << m << ' ' << n << '\n';

        for (int j = 1; j <= m; ++j) {
            cout << rows_idxs[j].size();

            if (!rows_idxs[j].empty()) {
                cout << ' ';
            }

            output_vector_no_newline(rows_idxs[j]);
            cout << '\n';

            output_vector_no_newline(rows_nums[j]);
            cout << '\n';
        }
    }
}
