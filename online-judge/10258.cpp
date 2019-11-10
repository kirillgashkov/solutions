#include <iostream>
#include <bitset>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <fstream>
using namespace std;


bool compare_scoreboard_entries(tuple<int, int, int> lhs, tuple<int, int, int> rhs) {
    int lhs_contestant = get<0>(lhs);
    int lhs_problems = get<1>(lhs);
    int lhs_penalty = get<2>(lhs);

    int rhs_contestant = get<0>(rhs);
    int rhs_problems = get<1>(rhs);
    int rhs_penalty = get<2>(rhs);


    if (lhs_problems != rhs_problems) {
        return lhs_problems > rhs_problems;
    }

    if (lhs_penalty != rhs_penalty) {
        return lhs_penalty < rhs_penalty;
    }

    return lhs_contestant < rhs_contestant;
}


int main() {
    int cases_n;
    cin >> cases_n;
    cin >> ws;

    for (int case_i = 0; case_i < cases_n; ++case_i) {
        if (case_i != 0) cout << '\n';

        unordered_map<int, vector<tuple<int, int, char>>> contestant_submissions;

        while (true) {
            string _submission;
            getline(cin, _submission);

            if (!cin or _submission.empty()) break;


            istringstream submission_stream(_submission);

            int _contestant, _problem, _time;
            char _verdict;
            submission_stream >> _contestant >> _problem >> _time >> _verdict;


            if (contestant_submissions.find(_contestant) == contestant_submissions.end()) {
                contestant_submissions[_contestant] = {};
            }
            contestant_submissions[_contestant].push_back({_problem, _time, _verdict});
        }

        unordered_map<int, bitset<9>> contestant_problems;
        unordered_map<int, int> contestant_penalties;

        for (auto& contestant_and_submissions : contestant_submissions) {
            int contestant = contestant_and_submissions.first;
            auto& submissions = contestant_and_submissions.second;

            contestant_problems[contestant] = bitset<9>();
            contestant_penalties[contestant] = 0;

            // set problems and calculate penalties for the first correct submissions
            for (auto& submission : submissions) {
                int problem = get<0>(submission);
                int time = get<1>(submission);
                int verdict = get<2>(submission);

                if (verdict == 'C' and contestant_problems[contestant][problem - 1] != 1) {
                    contestant_problems[contestant][problem - 1] = true;
                    contestant_penalties[contestant] += time;
                }

                // these penalties are falsely counted in the next loop
                if (verdict == 'I' and contestant_problems[contestant][problem - 1] == 1) {
                    contestant_penalties[contestant] -= 20;
                }
            }

            // calculate penalties for the incorrect submissions
            for (auto& submission : submissions) {
                int problem = get<0>(submission);
                int verdict = get<2>(submission);

                if (verdict == 'I' and contestant_problems[contestant][problem - 1] == 1) {
                    contestant_penalties[contestant] += 20;
                }
            }
        }


        vector<tuple<int, int, int>> scoreboard_entries;
        scoreboard_entries.reserve(contestant_problems.size());

        for (auto& contestant_and_submissions : contestant_submissions) {
            int contestant = contestant_and_submissions.first;

            int problems = contestant_problems[contestant].count();
            int penalty = contestant_penalties[contestant];

            scoreboard_entries.emplace_back(contestant, problems, penalty);
        }

        sort(scoreboard_entries.begin(), scoreboard_entries.end(), compare_scoreboard_entries);


        for (auto& entry : scoreboard_entries) {
            cout << get<0>(entry) << ' ' << get<1>(entry) << ' ' << get<2>(entry) << '\n';
        }
    }
}
