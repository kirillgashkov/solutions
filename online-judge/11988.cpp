#include <iostream>
#include <list>
#include <sstream>
using namespace std;


int main() {
    string line;

    while (getline(cin >> ws, line)) {
        istringstream line_stream(line);
        list<char> text;


        auto cursor = text.end();

        while (true) {
            char c = line_stream.get();

            if (!line_stream) break;

            switch (c) {
                case '[':
                    cursor = text.begin();
                    break;
                case ']':
                    cursor = text.end();
                    break;
                default:
                    text.insert(cursor, c);
                    break;
            }
        }


        for (auto& c : text) {
            putchar(c);
        }
        cout << '\n';
    }
}
