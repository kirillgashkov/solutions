#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    int cases_n;
    cin >> cases_n;

    for (int case_i = 0; case_i < cases_n; ++case_i) {
        unordered_map<char, int> char_prices;

        int chars_n;
        cin >> chars_n;

        for (int char_i = 0; char_i < chars_n; ++char_i) {
            char c;
            int price;
            cin >> c >> price;

            char_prices[c] = price;
        }


        int lines_n;
        cin >> lines_n;
        cin >> ws; // remove all leading whitespaces because we are going to read char by char


        unsigned long long total_cents = 0;

        char c;
        for (int line_i = 0; line_i < lines_n; ++line_i) {
            while (true) {
                c = getchar();

                if (c == '\n') break;
                if (char_prices.find(c) == char_prices.end()) continue;

                total_cents += char_prices[c];
            }
        }


        int dollars = total_cents / 100;
        int cents = total_cents % 100;

        printf("%d.%02d$\n", dollars, cents);
    }
}
