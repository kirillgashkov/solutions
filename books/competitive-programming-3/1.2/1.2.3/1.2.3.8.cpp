#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>

using namespace std;

#define INF 1000000000;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


int main(int argc, char const *argv[])
{
    ofstream fout("output.txt");

    int n = 10;

    vector<int> v(n);
    iota(v.begin(), v.end(), 0);

    const unsigned int number_of_subsets = 1 << n;
    for (unsigned int i = 0; i < number_of_subsets; ++i) {
        vector<int> subset;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subset.push_back(v[j]);
            }
        }
        for (auto& el : subset) {
            fout << el << ' ';
        }
        fout << '\n';
    }

    return 0;
}
