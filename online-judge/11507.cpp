#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


const unordered_map<string, int> stoi_direction = {
    {"No", 0},
    {"+x", 1},
    {"-x", 2},
    {"+y", 3},
    {"-y", 4},
    {"+z", 5},
    {"-z", 6},
};
const unordered_map<int, string> itos_direction = {
    {0, "No"},
    {1, "+x"},
    {2, "-x"},
    {3, "+y"},
    {4, "-y"},
    {5, "+z"},
    {6, "-z"},
};


int main() {
    int L;
    cin >> L;
    while (L != 0) {
        int d = 1;
        for (int j = 1; j < L; ++j) {
            string bend;
            cin >> bend;
            int bd = stoi_direction.at(bend);
            switch (bd) {
            case 0: break;
            case 3:
                switch (d) {
                case 1: d = 3; break;
                case 2: d = 4; break;
                case 3: d = 2; break;
                case 4: d = 1; break;
                case 5:
                case 6: break;
                }
                break;
            case 4:
                switch (d) {
                case 1: d = 4; break;
                case 2: d = 3; break;
                case 3: d = 1; break;
                case 4: d = 2; break;
                case 5:
                case 6: break;
                }
                break;
            case 5:
                switch (d) {
                case 1: d = 5; break;
                case 2: d = 6; break;
                case 3: 
                case 4: break;
                case 5: d = 2; break;
                case 6: d = 1; break;
                }
                break;
            case 6:
                switch (d) {
                case 1: d = 6; break;
                case 2: d = 5; break;
                case 3: 
                case 4: break;
                case 5: d = 1; break;
                case 6: d = 2; break;
                }
                break;
            }
        }
        cout << itos_direction.at(d) << '\n';
        cin >> L;
    }
}
