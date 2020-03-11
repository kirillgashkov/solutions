#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#define INF 1000000000;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


int main(int argc, char const *argv[])
{
    ifstream fin("input.txt");

    string numbers;
    while (getline(fin, numbers)) {
        istringstream numbers_stream(numbers);
        int number;
        int total = 0;
        while (numbers_stream >> number) {
            total += number;
        }
        cout << total << '\n';
    }

    return 0;
}
