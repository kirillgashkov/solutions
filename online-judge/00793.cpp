#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

#define umap unordered_map


struct UnionFind {
    umap<int, int> p;
    umap<int, int> r;

    void make_set(int v) {
        p[v] = v;
    }
    int find_set(int v) {
        if (p[v] == v) {
            return v;
        }
        return p[v] = find_set(p[v]);
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);

        if (r[a] < r[b]) {
            swap(a, b);
        }
        p[b] = a;
        if (r[a] == r[b]) {
            r[a] += 1;
        }
    }
};


int main() {
    int t;
    cin >> t;

    for (int i_t = 0; i_t < t; ++i_t) {
        if (i_t != 0) cout << '\n';


        UnionFind computers;


        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i) {
            computers.make_set(i);
        }


        int plus_count = 0;
        int minus_count = 0;


        cin >> ws;
        while (true) {
            string line;
            getline(cin, line);

            if (line.empty()) break;

            istringstream line_cin(line);


            char kind;
            line_cin >> kind;

            int a, b;
            line_cin >> a >> b;

            if (kind == 'c') {
                computers.union_sets(a, b);
            } else {
                if (computers.find_set(a) == computers.find_set(b)) {
                    ++plus_count;
                } else {
                    ++minus_count;
                }
            }
        }


        cout << plus_count << ',' << minus_count << '\n';
    }
}
