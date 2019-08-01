#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (--n) {
        int a;
        int b;
        cin >> a >> b;
        if (a < b) {
            cout << "<\n";
        } else if (a > b) {
            cout << ">\n";
        } else {
            cout << "=\n";
        }
    }
}