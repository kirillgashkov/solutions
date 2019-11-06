#include <iostream>
using namespace std;


int gcd(int a, int b) {
    int t;

    while (b != 0) {
        t = a;
        a = b;
        b = t % b;
    }

    return a;
}


struct Ratio {
    bool is_negative;
    int wholes;
    int numerator;
    int denominator;

    string sign_prefix;


    Ratio(int n, int d) {
        is_negative = float(n) / float(d) < 0;
        numerator = abs(n);
        denominator = abs(d);

        wholes = numerator / denominator;
        numerator = numerator % denominator;

        if (numerator != 0) {
            int c = gcd(numerator, denominator);
            numerator /= c;
            denominator /= c;
        }
    }
};


int calc_number_width(int n) {
    int width = 1;

    while (n > 9) {
        width += 1;
        n /= 10;
    }

    return width;
}


void print_integer(int sum, int count) {
    bool has_minus = sum / count < 0;

    if (has_minus) cout << "- ";
    cout << abs(sum / count) << '\n';
}


void print_ratio(int sum, int count) {
    Ratio ratio(sum, count);


    int prefix_width = 0;
    prefix_width += ratio.is_negative ? 2 : 0;
    prefix_width += ratio.wholes != 0 ? calc_number_width(ratio.wholes) : 0;

    int ratio_width = calc_number_width(ratio.denominator);
    int numerator_filler_width = ratio_width - calc_number_width(ratio.numerator);


    for (int i = 0; i < prefix_width + numerator_filler_width; ++i) cout << ' ';
    cout << ratio.numerator << '\n';

    if (ratio.is_negative) cout << "- ";
    if (ratio.wholes != 0) cout << ratio.wholes;
    for (int i = 0; i < ratio_width; ++i) cout << '-';
    cout << '\n';

    for (int i = 0; i < prefix_width; ++i) cout << ' ';
    cout << ratio.denominator << '\n';
}


int main() {
    int case_number = 0;

    while (true) {
        ++case_number;

        int count;
        cin >> count;

        if (count == 0) {
            break;
        }

        int sum = 0;
        for (int i = 0;  i < count; ++i) {
            int x;
            cin >> x;
            sum += x;
        }


        cout << "Case " << case_number << ":\n";
        if (sum % count == 0) {
            print_integer(sum, count);
        } else {
            print_ratio(sum, count);
        }
    }
}
