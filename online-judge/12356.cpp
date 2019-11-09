#include <iostream>
#include <vector>
using namespace std;


#define vi vector<int>
#define NO_BUDDY -1


struct Soldier {
    int left_buddy;
    int right_buddy;


    Soldier(int l, int r) {
        left_buddy = l;
        right_buddy = r;
    }


    bool has_left() {
        return left_buddy != NO_BUDDY;
    }

    bool has_right() {
        return right_buddy != NO_BUDDY;
    }
};


pair<int, int> handle_explosion(vector<Soldier>& soldiers, int l, int r) {
    // we will update the extreme ones only
    Soldier& left = soldiers[l];
    Soldier& right = soldiers[r];

    int new_left_i = left.left_buddy;
    int new_right_i = right.right_buddy;

    if (left.has_left()) {
        soldiers[left.left_buddy].right_buddy = new_right_i;
    }

    if (right.has_right()) {
        soldiers[right.right_buddy].left_buddy = new_left_i;
    }

    return {new_left_i, new_right_i};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int s, b;
        cin >> s >> b;

        if (s == 0) break;


        vector<Soldier> soldiers;
        soldiers.reserve(s + 2);

        // leftmost dead dummy
        soldiers.emplace_back(Soldier(NO_BUDDY, NO_BUDDY));
        if (s == 1) {
            soldiers.emplace_back(Soldier(NO_BUDDY, NO_BUDDY));
        } else {
            soldiers.emplace_back(Soldier(NO_BUDDY, 2));
            for (int i = 2; i < s; ++i) {
                soldiers.emplace_back(Soldier(i - 1, i + 1));
            }
            soldiers.emplace_back(Soldier(s - 1, NO_BUDDY));
        }
        // rightmost dead dummy
        soldiers.emplace_back(Soldier(NO_BUDDY, NO_BUDDY));


        for (int i = 0; i < b; ++i) {
            int l, r;
            cin >> l >> r;


            pair<int, int> lr = handle_explosion(soldiers, l, r);


            if (lr.first == NO_BUDDY) cout << '*';
            else cout << lr.first;

            cout << ' ';

            if (lr.second == NO_BUDDY) cout << '*';
            else cout << lr.second;

            cout << '\n';
        }

        cout << "-\n";
    }
}
