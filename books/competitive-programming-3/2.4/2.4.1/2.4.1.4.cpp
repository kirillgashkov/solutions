#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

#define ii pair<int, int>
#define vi vector<int>


void adj_matrix_count_vertices_and_edges(vector<vi>& adj_matrix) {
    int v = adj_matrix.size();

    int e = 0;
    for (int v1 = 0; v1 < v; ++v1) {
        for (int v2 = 0; v2 < v; ++v2) {
            if (adj_matrix[v1][v2] != 0) {
                e += 1;
            }
        }
    }

    cout << v << " vertices\n";
    cout << e << " edges\n";
}


void adj_matrix_count_in_n_out_degrees(vector<vi>& adj_matrix, int v1) {
    int in_k = 0;
    int out_k = 0;

    for (int v2 = 0; v2 < adj_matrix.size(); ++v2) {
        if (adj_matrix[v1][v2] != 0) {
            out_k += 1;
        }

        if (adj_matrix[v2][v1] != 0) {
            in_k += 1;
        }
    }

    cout << in_k << " in-degree\n";
    cout << out_k << " out-degree\n";
}


void adj_matrix_transposed(vector<vi>& adj_matrix) {
    int v = adj_matrix.size();

    // we cannot use this algorithm on the same matrix since the values change
    vector<vi> transposed_adj_matrix(adj_matrix);

    for (int v1 = 0; v1 < v; ++v1) {
        for (int v2 = 0; v2 < v; ++v2) {
            transposed_adj_matrix[v1][v2] = adj_matrix[v1][v2];
        }
    }

    for (int v1 = 0; v1 < v; ++v1) {
        for (int v2 = 0; v2 < v; ++v2) {
            cout << transposed_adj_matrix[v1][v2] << ' ';
        }
        cout << '\n';
    }
}


void adj_matrix_is_complete(vector<vi>& adj_matrix) {
    int v = adj_matrix.size();

    bool is_complete = true;

    for (int v1 = 0; v1 < v; ++v1) {
        for (int v2 = 0; v2 < v; ++v2) {
            if (adj_matrix[v1][v2] != 0) {
                is_complete = false;
            }
        }
    }

    cout << "is complete: " << is_complete << '\n';
}


void adj_matrix_is_tree(vector<vi>& adj_matrix) {
    // https://stackoverflow.com/questions/20556802/determining-whether-or-not-a-directed-or-undirected-graph-is-a-tree
}


void adj_matrix_is_star(vector<vi>& adj_matrix) {
    // https://www.tutorialspoint.com/Check-For-Star-Graph
}


int main() {
    // 10
    // 1 2 6
    // 1 3 6
    // 1 4 6
    // 1 0 7
    // 2 0 7
    // 2 4 7
    // 2 3 3
    // 3 0 3
    // 3 4 3
    // 4 0 2


    int e;
    cin >> e;

    vector<pair<int, ii>> edge_list;
    edge_list.reserve(e);

    int v = -1;

    for (int i = 0; i < e; ++i) {
        int weight, v1, v2;
        cin >> weight >> v1 >> v2;

        v = max(v, max(v1, v2));

        edge_list.emplace_back(weight, v1, v2);
        edge_list.emplace_back(weight, v2, v1);
    }

    v += 1;
    
    
    // test functions here
}
