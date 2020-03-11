#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <utility>

using namespace std;

#define INF 1000000000;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;


int main(int argc, char const *argv[])
{
    FILE* fin = fopen("input.txt", "r");
    int day, month, year;

    vector<tuple<int, int, int>> birthdays;
    while (fscanf(fin, "(%d, %d, %d)\n", &day, &month, &year) != EOF) {
        birthdays.push_back({day, month, year});
    }
    vector<tuple<int, int, int>*> pointers;
    for (auto& d : birthdays) {
        pointers.push_back(&d);
    }
    
    vector<tuple<int, int, int>*> sorted_by_month = pointers;
    sort(sorted_by_month.begin(), sorted_by_month.end(), [](tuple<int, int, int>* d1, tuple<int, int, int>* d2) {
        return get<1>(*d1) < get<1>(*d2);
    });

    vector<tuple<int, int, int>*> sorted_by_day = pointers;
    sort(sorted_by_day.begin(), sorted_by_day.end(), [](tuple<int, int, int>* d1, tuple<int, int, int>* d2) {
        return get<0>(*d1) < get<0>(*d2);
    });

    vector<tuple<int, int, int>*> sorted_by_age = pointers;
    sort(sorted_by_age.begin(), sorted_by_age.end(), [](tuple<int, int, int>* d1, tuple<int, int, int>* d2) {
        int composed_d1 = get<0>(*d1) + get<1>(*d1) * 100 + get<2>(*d1) * 10000;
        int composed_d2 = get<0>(*d2) + get<1>(*d2) * 100 + get<2>(*d2) * 10000;
        return composed_d1 < composed_d2;
    });

    cout << "[Birthdays]\n";
    for (auto& d : birthdays) {
        cout << get<0>(d) << ' ' << get<1>(d) << ' ' << get<2>(d) << '\n';
    }

    cout << "\n[Sorted by month]\n";
    for (auto* d : sorted_by_month) {
        cout << get<0>(*d) << ' ' << get<1>(*d) << ' ' << get<2>(*d) << '\n';
    }

    cout << "\n[Sorted by day]\n";
    for (auto* d : sorted_by_day) {
        cout << get<0>(*d) << ' ' << get<1>(*d) << ' ' << get<2>(*d) << '\n';
    }

    cout << "\n[Sorted by age]\n";
    for (auto* d : sorted_by_age) {
        cout << get<0>(*d) << ' ' << get<1>(*d) << ' ' << get<2>(*d) << '\n';
    }

    return 0;
}
