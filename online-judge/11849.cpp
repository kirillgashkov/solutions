#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    while (true) {
        int n, m;
        cin >> n >> m;

        if (n == 0 and m == 0) {
            break;
        }


        vector<int> N;
        vector<int> M;

        for (int i = 0; i < n; ++i) {
            int disk;
            cin >> disk;
            N.push_back(disk);
        }

        for (int i = 0; i < m; ++i) {
            int disk;
            cin >> disk;
            M.push_back(disk);
        }


        vector<int> common;

        set_intersection(N.begin(), N.end(), M.begin(), M.end(), back_inserter(common));

        cout << common.size() << '\n';
    }
}
