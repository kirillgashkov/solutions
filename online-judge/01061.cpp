#include <iostream>
#include <set>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

#define vs vector<string>
#define map unordered_map

map<string, vs> raw_combos_for_blood = {
    {"AB+", {"AB++", "AB+-"}},
    {"AB-", {"AB--"}},
    {"A+", {"AA++", "AA+-", "AO++", "AO+-"}},
    {"A-", {"AA--", "AO--"}},
    {"B+", {"BB++", "BB+-", "BO++", "BO+-"}},
    {"B-", {"BB--", "BO--"}},
    {"O+", {"OO++", "OO+-"}},
    {"O-", {"OO--"}},
};

struct Combo {
  map<char, int> allele_counts = {
      {'A', 0}, {'B', 0}, {'O', 0}, {'+', 0}, {'-', 0},
  };

  Combo(string& raw_combo) {
    for (auto& allele : raw_combo) {
      ++allele_counts[allele];
    }
  }
};

vector<Combo> make_combos_from_blood(string& blood) {
  if (blood == "?") {
    return {};
  }

  vs& raw_combos = raw_combos_for_blood[blood];

  vector<Combo> combos;
  combos.reserve(raw_combos.size());

  for (auto& raw_combo : raw_combos) {
    combos.emplace_back(Combo(raw_combo));
  }

  return combos;
}

map<string, vector<Combo>> make_all_blood_combos() {
  map<string, vector<Combo>> blood_combos;

  for (auto& blood_and_raw_combos : raw_combos_for_blood) {
    auto blood = const_cast<string&>(blood_and_raw_combos.first);
    blood_combos[blood] = make_combos_from_blood(blood);
  }

  return blood_combos;
}

vector<char> ABO_ALLELES = {'A', 'B', 'O'};
vector<char> RH_ALLELES = {'+', '-'};

bool can_such_child_exist(map<char, int>& mother_counts,
                          map<char, int>& father_counts,
                          map<char, int>& child_counts) {
  vector<map<char, int>> all_possible_child_counts;

  for (auto& mom_abo_allele : ABO_ALLELES) {
    for (int i = 0; i < mother_counts[mom_abo_allele]; ++i) {
      for (auto& dad_abo_allele : ABO_ALLELES) {
        for (int j = 0; j < father_counts[dad_abo_allele]; ++j) {
          for (auto& mom_rh_allele : RH_ALLELES) {
            for (int k = 0; k < mother_counts[mom_rh_allele]; ++k) {
              for (auto& dad_rh_allele : RH_ALLELES) {
                for (int l = 0; l < father_counts[dad_rh_allele]; ++l) {
                  map<char, int> counts = {
                      {'A', 0}, {'B', 0}, {'O', 0}, {'+', 0}, {'-', 0},
                  };

                  ++counts[mom_abo_allele];
                  ++counts[dad_abo_allele];
                  ++counts[mom_rh_allele];
                  ++counts[dad_rh_allele];

                  all_possible_child_counts.push_back(counts);
                }
              }
            }
          }
        }
      }
    }
  }

  for (auto& possible_child_counts : all_possible_child_counts) {
    bool is_possible = possible_child_counts['A'] == child_counts['A'] and
                       possible_child_counts['B'] == child_counts['B'] and
                       possible_child_counts['O'] == child_counts['O'] and
                       possible_child_counts['+'] == child_counts['+'] and
                       possible_child_counts['-'] == child_counts['-'];
    if (is_possible)
      return true;
  }

  return false;
}

string format_mystery_bloods(set<string>& bloods) {
  if (bloods.empty()) {
    return "IMPOSSIBLE";
  }
  if (bloods.size() == 1) {
    return *bloods.begin();
  }

  ostringstream s;

  auto iter = bloods.begin();

  s << '{' << *iter;
  for (++iter; iter != bloods.end(); ++iter) {
    s << ", " << *iter;
  }
  s << '}';

  return s.str();
}

int main() {
  int case_number = 0;

  while (true) {
    ++case_number;

    string mother_blood;
    string father_blood;
    string child_blood;

    cin >> mother_blood >> father_blood >> child_blood;

    if (mother_blood == "E") {
      break;
    }

    bool did_swap_parents = false;

    // let father always be the mystery guy
    if (mother_blood == "?") {
      swap(mother_blood, father_blood);
      did_swap_parents = true;
    }

    bool is_child_mystery = child_blood == "?";

    vector<Combo> mother_combos = make_combos_from_blood(mother_blood);
    vector<Combo> father_combos = make_combos_from_blood(father_blood);
    vector<Combo> child_combos = make_combos_from_blood(child_blood);

    set<string> possible_mystery_bloods;

    map<string, vector<Combo>> mystery_blood_combos = make_all_blood_combos();

    for (auto& blood_and_combos : mystery_blood_combos) {
      auto blood = const_cast<string&>(blood_and_combos.first);
      vector<Combo>& combos = blood_and_combos.second;

      for (auto& mystery_combo : combos) {
        for (auto& mother_combo : mother_combos) {
          if (is_child_mystery) {
            for (auto& father_combo : father_combos) {
              bool is_possible = can_such_child_exist(
                  mother_combo.allele_counts, father_combo.allele_counts,
                  mystery_combo.allele_counts);

              if (is_possible) {
                possible_mystery_bloods.insert(blood);
                goto next_blood;
              }
            }
          } else {
            for (auto& child_combo : child_combos) {
              bool is_possible = can_such_child_exist(
                  mother_combo.allele_counts, mystery_combo.allele_counts,
                  child_combo.allele_counts);

              if (is_possible) {
                possible_mystery_bloods.insert(blood);
                goto next_blood;
              }
            }
          }
        }

      next_blood:;
      }
    }

    cout << "Case " << case_number << ": ";
    if (is_child_mystery) {
      cout << mother_blood << ' ' << father_blood << ' '
           << format_mystery_bloods(possible_mystery_bloods);
    } else if (did_swap_parents) {
      cout << format_mystery_bloods(possible_mystery_bloods) << ' '
           << mother_blood << ' ' << child_blood;
    } else {
      cout << mother_blood << ' '
           << format_mystery_bloods(possible_mystery_bloods) << ' '
           << child_blood;
    }
    cout << '\n';
  }
}
