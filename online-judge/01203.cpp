#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define intl long long


struct Instruction {
    int code;
    int period;
    intl next_time;

    Instruction(int code, int period) {
        this->code = code;
        this->period = period;
        this->next_time = period;
    }
};


bool cmp_instructions_by_code(Instruction& lhs, Instruction& rhs) {
    return lhs.code < rhs.code;
}


bool cmp_instructions_by_period(Instruction& lhs, Instruction& rhs) {
    return lhs.period < rhs.period;
}


int gcd(int a, int b) {
    while (b != 0) {
        int a_t = a;
        a = b;
        b = a_t % b;
    }

    return a;
}

int main() {
    vector<Instruction> instrs;
    int delta = -1;

    while (true) {
        string command;
        cin >> command;

        if (command == "#") {
            break;
        }


        int code, period;
        cin >> code >> period;
        Instruction instr(code, period);
        if (delta == -1) {
            delta = period;
        } else {
            delta = gcd(delta, period);
        }


        instrs.push_back(instr);
    }

    sort(instrs.begin(), instrs.end(), cmp_instructions_by_code);


    int target_k;
    cin >> target_k;


    int k = 0;
    intl clock = 0;

    while (k != target_k) {
        clock += delta;
        for (auto& instr : instrs) {
            if (instr.next_time <= clock) {
                cout << instr.code << '\n';
                instr.next_time += instr.period;
                k += 1;
            }
        }
    }
}
