#include <iostream>
#include <vector>

#define INF 1000000000;

using namespace std;


int get_price_if_ok(int& N, int& B, int& price_per_person, vector<int>& week_beds) {
    int price = N * price_per_person;
    if (price > B) {
        return -1;
    }
    for (auto& beds_n : week_beds) {
        if (beds_n >= N) {
            return price;
        }
    }
    return -1;
}


int find_cheapest_price(int N, int B, int H, int W) {
    vector<int> hotel_person_prices;
    vector<vector<int>> hotel_week_beds;
    for (int i = 0; i < H; ++i) {
        int price_per_person;
        vector<int> week_beds;

        cin >> price_per_person;
        for (int j = 0; j < W; ++j) {
            int beds_n;
            cin >> beds_n;
            week_beds.push_back(beds_n);
        }

        hotel_person_prices.push_back(price_per_person);
        hotel_week_beds.push_back(week_beds);
    }

    int best_price = INF;
    for (int i = 0; i < H; ++i) {
        int price = get_price_if_ok(N, B, hotel_person_prices[i], hotel_week_beds[i]);
        if (price != -1 && price < best_price) {
            best_price = price;
        }
    }
    if (best_price != 1000000000) {
        return best_price;
    }

    return -1;
}


int main() {
    int N;
    int B;
    int H;
    int W;

    while (cin >> N >> B >> H >> W) {
        int price = find_cheapest_price(N, B, H, W);
        if (price == -1) {
            cout << "stay home\n";
        } else {
            cout << price << '\n';
        }
    }
}
