#include <iostream>

using namespace std;

int main() {
    int number_of_queries = 1;
    while (number_of_queries) {
        cin >> number_of_queries;
        int center_x;
        int center_y;
        cin >> center_x >> center_y;
        int n = number_of_queries;
        while (n) {
            --n;
            int x;
            int y;
            cin >> x >> y;
            bool is_border = x == center_x || y == center_y;
            bool is_up = y > center_y;
            bool is_right = x > center_x;
            if (is_border) {
                cout << "divisa\n";
            } else if (is_up && is_right) {
                cout << "NE\n";
            } else if (is_up && !is_right) {
                cout << "NO\n";
            } else if (!is_up && is_right) {
                cout << "SE\n";
            } else if (!is_up && !is_right) {
                cout << "SO\n";
            }
        }
    }
}