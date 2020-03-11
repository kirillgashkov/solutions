#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

#define INF 1000000000;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


int main(int argc, char const *argv[])
{
    ofstream fout("output.txt");

    // generate them using `char(i)` where `i` is somewhere in [0, 255]
    vector<char> letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    do {
        for (auto& l : letters) {
            fout << l;
        }
        fout << '\n';
    } while (next_permutation(letters.begin(), letters.end()));

    return 0;
}
