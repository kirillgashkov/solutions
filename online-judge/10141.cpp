#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

string get_best_proposal(int req_n, int prop_n) {
  unordered_set<string> requirements;
  for (int i = 0; i < req_n; ++i) {
    string req;
    getline(cin >> ws, req);
    requirements.insert(req);
  }

  vector<string> prop_names;
  vector<int> prop_prices;
  vector<unordered_set<string>> prop_requirements;
  for (int i = 0; i < prop_n; ++i) {
    string name;
    getline(cin >> ws, name);
    prop_names.push_back(name);

    float price;
    int n;
    cin >> price >> n;
    prop_prices.push_back(price);
    unordered_set<string> reqs;
    for (int i = 0; i < n; ++i) {
      string req;
      getline(cin >> ws, req);
      reqs.insert(req);
    }
    prop_requirements.push_back(reqs);
  }

  int max_prop_i = -1;
  float max_compliance = -1;
  for (int i = 0; i < prop_n; ++i) {
    unordered_set<string>& reqs = prop_requirements[i];
    float compliance = (float)reqs.size() / (float)req_n;
    if ((compliance > max_compliance) ||
        (compliance == max_compliance &&
         prop_prices[i] < prop_prices[max_prop_i])) {
      max_prop_i = i;
      max_compliance = compliance;
    }
  }

  return prop_names[max_prop_i];
}

int main() {
  int req_n;
  int prop_n;

  int rfp_counter = 0;
  cin >> req_n >> prop_n;
  while (req_n != 0 && prop_n != 0) {
    if (rfp_counter != 0) {
      cout << '\n';
    }
    ++rfp_counter;
    string best_prop_name = get_best_proposal(req_n, prop_n);
    cout << "RFP #" << rfp_counter << '\n' << best_prop_name << '\n';
    cin >> req_n >> prop_n;
  }
}
