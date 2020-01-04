#include <iostream>
#include <unordered_map>
using namespace std;

#define umap unordered_map


#define uft string
struct UnionFind {
    umap<uft, uft> p;
    umap<uft, int> s;

    void make_set(uft v) {
        p[v] = v;
        s[v] = 1;
    }
    uft find_set(uft v) {
        if (p[v] == v) {
            return v;
        }
        return p[v] = find_set(p[v]);
    }
    void union_sets(uft a, uft b) {
        a = find_set(a);
        b = find_set(b);

        if (s[a] < s[b]) {
            swap(a, b);
        }

        p[b] = a;

        if (a != b) {
            s[a] += s[b];
        }
    }
    void make_set_if_needed(uft v) {
        if (p.find(v) == p.end()) make_set(v);
    }
};


int main() {
    int t;
    cin >> t;

    for (int i_t = 0; i_t < t; ++i_t) {
        int n;
        cin >> n;

        UnionFind networks;

        for (int i = 0; i < n; ++i) {
            string a, b;
            cin >> a >> b;

            networks.make_set_if_needed(a);
            networks.make_set_if_needed(b);

            networks.union_sets(a, b);

            cout << networks.s[networks.find_set(a)] << '\n';
        }
    }
}
