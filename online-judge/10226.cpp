#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;


int main() {
    int t;
    cin >> t >> ws;

    for (int i_t = 0; i_t < t; ++i_t) {
        if (i_t != 0) {
            cout << '\n';
        }

        unordered_map<string, int> trees;

        while (true) {
            string tree;
            getline(cin, tree);

            if (tree.empty() or !cin) {
                break;
            }


            if (trees.find(tree) == trees.end()) {
                trees[tree] = 0;
            }
            trees[tree] += 1;
        }


        int total = 0;

        for (auto& tree_count : trees) {
            total += tree_count.second;
        }


        vector<string> tree_percentages;
        tree_percentages.reserve(trees.size());

        for (auto& tree_count : trees) {
            ostringstream tree_percentage;
            tree_percentage << tree_count.first << ' ';
            tree_percentage.precision(4);
            tree_percentage << fixed;
            tree_percentage << float(tree_count.second) / float(total) * 100.0;
            tree_percentages.push_back(tree_percentage.str());
        }


        sort(tree_percentages.begin(), tree_percentages.end());

        for (auto& tree_percentage : tree_percentages) {
            cout << tree_percentage << '\n';
        }
    }
}
