#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int TIME_MOVE = 2;
const int TIME_LOAD_SINGLE_CARGO = 1;
const int TIME_UNLOAD_SINGLE_CARGO = 1;

struct Carrier {
  int capacity;
  int station_capacity;
  int cargo_n_left;

  int station_i = 1;
  stack<int> cargo_stack = {};

  int timer = 0;

  Carrier(int capacity, int station_capacity, int cargo_n_left) {
    this->capacity = capacity;
    this->station_capacity = station_capacity;
    this->cargo_n_left = cargo_n_left;
  }
};

void unload(Carrier& carrier, vector<queue<int>>& stations) {
  queue<int>& station = stations[carrier.station_i];

  while (!carrier.cargo_stack.empty()) {
    if (carrier.cargo_stack.top() == carrier.station_i) {
      carrier.cargo_stack.pop();
      --carrier.cargo_n_left;
    } else if (station.size() < carrier.station_capacity) {
      int cargo = carrier.cargo_stack.top();
      station.push(cargo);
      carrier.cargo_stack.pop();
    } else {
      break;
    }

    carrier.timer += TIME_UNLOAD_SINGLE_CARGO;
  }
}

void load(Carrier& carrier, vector<queue<int>>& stations) {
  while (carrier.cargo_stack.size() < carrier.capacity &&
         !stations[carrier.station_i].empty()) {
    carrier.cargo_stack.push(stations[carrier.station_i].front());
    stations[carrier.station_i].pop();
    carrier.timer += TIME_LOAD_SINGLE_CARGO;
  }
}

void move(Carrier& carrier, vector<queue<int>>& stations) {
  int next_station_i = carrier.station_i + 1;
  if (carrier.station_i == stations.size() - 1) {
    next_station_i = 1;
  }
  carrier.station_i = next_station_i;
  carrier.timer += TIME_MOVE;
}

int main() {
  int cases_n;
  cin >> cases_n;

  for (int case_i = 0; case_i < cases_n; ++case_i) {
    int stations_n, carrier_capacity, station_capacity;
    cin >> stations_n >> carrier_capacity >> station_capacity;

    int cargo_n_total = 0;
    // the first element is dummy to create index offset
    vector<queue<int>> stations;
    stations.resize(stations_n + 1);

    for (int i = 1; i <= stations_n; ++i) {
      stations[i] = {};

      int cargo_n;
      cin >> cargo_n;
      cargo_n_total += cargo_n;

      for (int j = 0; j < cargo_n; ++j) {
        int cargo;
        cin >> cargo;

        stations[i].push(cargo);
      }
    }

    Carrier carrier(carrier_capacity, station_capacity, cargo_n_total);

    while (true) {
      unload(carrier, stations);
      load(carrier, stations);

      if (carrier.cargo_n_left <= 0) {
        break;
      }

      move(carrier, stations);
    }

    cout << carrier.timer << '\n';
  }
}
