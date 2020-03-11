#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

#define INF 1000000000;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


int main(int argc, char const *argv[])
{
    ifstream fin("input.txt");
    int precision;
    fin >> precision;
    printf("%.*f\n", precision, M_PI);
    return 0;
}
