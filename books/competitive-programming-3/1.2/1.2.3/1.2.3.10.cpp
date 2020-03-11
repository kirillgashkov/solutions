#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

#define INF 1000000000;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


int main(int argc, char const *argv[])
{
    ifstream fin("input.txt");

    string line;
    while (getline(fin, line)) {
        regex pattern(R"(\b[a-z][0-9]{2}\b)");
        cout << regex_replace(line, pattern, "***") << '\n';
    }

    return 0;
}
