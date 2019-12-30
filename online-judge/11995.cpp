#include <iostream>
#include <queue>
#include <stack>
using namespace std;


int main() {
    while (true) {
        int n;
        cin >> n;

        if (!cin) {
            break;
        }


        stack<int> s;
        queue<int> q;
        priority_queue<int> p;

        bool s_possible = true;
        bool q_possible = true;
        bool p_possible = true;

        for (int i = 0; i < n; ++i) {
            int type;
            int number;
            cin >> type >> number;

            int s_number;
            int q_number;
            int p_number;

            switch (type) {
                case 1:
                    s.push(number);
                    q.push(number);
                    p.push(number);
                    break;
                case 2:
                    if (s.empty()) {
                        s_possible = false;
                        q_possible = false;
                        p_possible = false;
                        break;
                    }

                    s_number = s.top();
                    q_number = q.front();
                    p_number = p.top();

                    s.pop();
                    q.pop();
                    p.pop();

                    if (s_number != number) {
                        s_possible = false;
                    }
                    if (q_number != number) {
                        q_possible = false;
                    }
                    if (p_number != number) {
                        p_possible = false;
                    }
                    break;
                default:
                    break;
            }
        }


        if (s_possible and !q_possible and !p_possible) {
            cout << "stack" << '\n';
        } else if (!s_possible and q_possible and !p_possible) {
            cout << "queue" << '\n';
        } else if (!s_possible and !q_possible and p_possible) {
            cout << "priority queue" << '\n';
        } else if (!s_possible and !q_possible and !p_possible) {
            cout << "impossible" << '\n';
        } else {
            cout << "not sure" << '\n';
        }
    }
}
