#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>
using namespace std;


string format_instructions(vector<bool>& instructions) {
    ostringstream out;

    out << (instructions[0] ? 'i' : 'o');
    for (int i = 1; i < int(instructions.size()); ++i) {
        out << ' ' << (instructions[i] ? 'i' : 'o');
    }

    return out.str();
}


void output_all_instructions(
        string& src, string& dst,
        int src_i, int dst_i,
        bool should_push, stack<char> buffer,
        int input_count, int output_count,
        vector<bool> prefix
        ) {
    if (should_push) {
        buffer.push(src[src_i]);
        src_i += 1;
        prefix.push_back(true);
        input_count += 1;
    } else {
        if (buffer.empty()) {
            return;
        }
        if (buffer.top() != dst[dst_i]) {
            return;
        }
        buffer.pop();
        dst_i += 1;
        prefix.push_back(false);
        output_count += 1;
    }

    if (prefix.size() == 2 * src.size()) {
        cout << format_instructions(prefix) << '\n';
    } else {
        if (input_count < int(src.size())) {
            output_all_instructions(
                    src, dst,
                    src_i, dst_i,
                    true, buffer,
                    input_count, output_count,
                    prefix);
        }
        if (output_count < int(src.size())) {
            output_all_instructions(
                    src, dst,
                    src_i, dst_i,
                    false, buffer,
                    input_count, output_count,
                    prefix);
        }
    }
}


bool has_solutions(string& src, string& dst) {
    string src_c(src);
    string dst_c(dst);

    sort(src_c.begin(), src_c.end());
    sort(dst_c.begin(), dst_c.end());

    return src_c == dst_c;
}


int main() {
    while (true) {
        string src;
        string dst;

        getline(cin, src);
        if (!cin) break;
        getline(cin, dst);


        if (!has_solutions(src, dst)) {
            cout << "[\n";
            cout << "]\n";
            continue;
        }


        stack<char> buffer;
        vector<bool> instructions;

        cout << "[\n";
        output_all_instructions(
                src, dst,
                0, 0,
                true, buffer,
                0, 0,
                instructions);
        cout << "]\n";
    }
}
