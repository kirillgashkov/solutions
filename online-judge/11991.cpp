#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define vi vector<int>


int main() {
    while (true) {
        int n, m;
        cin >> n >> m;

        if (!cin) break;


        unordered_map<int, vi> nums;

        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;

            if (nums.find(num) == nums.end()) {
                nums[num] = {};
            }
            nums[num].push_back(i);
        }


        for (int j = 0; j < m; ++j) {
            int k, v;
            cin >> k >> v;

            if (nums[v].size() < k) {
                cout << 0 << '\n';
            } else {
                cout << nums[v][k - 1] + 1 << '\n';
            }
        }
    }
}
