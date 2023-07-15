#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Car {
  int arrival_time;
  int finish_time;
  bool is_on_left;

  Car(int time, string& side) {
    arrival_time = time;
    is_on_left = side[0] == 'l';
  }
};

struct Ferry {
  int timer = 0;
  int time_to_cross;

  bool is_on_left = true;
  vector<Car*> cars_now;
  int max_cars;

  Ferry(int n, int t) {
    time_to_cross = t;
    max_cars = n;
  }
};

int main() {
  int cases_n;
  cin >> cases_n;

  for (int case_i = 0; case_i < cases_n; ++case_i) {
    if (case_i != 0)
      cout << '\n';

    int max_cars, time_to_cross, m;
    cin >> max_cars >> time_to_cross >> m;

    Ferry ferry(max_cars, time_to_cross);

    vector<Car> cars;
    int car_i = 0;

    for (int i = 0; i < m; ++i) {
      int arrival_time;
      string side;
      cin >> arrival_time >> side;

      cars.emplace_back(Car(arrival_time, side));
    }

    int last_car_i = int(cars.size()) - 1;

    queue<Car*> left_q;
    queue<Car*> right_q;

    while (true) {
      if (car_i > last_car_i && left_q.empty() && right_q.empty())
        break;

      // update queues
      if (car_i <= last_car_i && cars[car_i].arrival_time <= ferry.timer) {
        Car& car = cars[car_i];

        if (car.is_on_left) {
          left_q.push(&car);
        } else {
          right_q.push(&car);
        }

        ++car_i;
        continue;
      }

      // wait for a car
      if (left_q.empty() && right_q.empty()) {
        ferry.timer = cars[car_i].arrival_time;
        continue;
      }

      // handle cars
      if (!left_q.empty() && ferry.is_on_left) {
        while (ferry.cars_now.size() < ferry.max_cars && !left_q.empty()) {
          ferry.cars_now.push_back(left_q.front());
          left_q.pop();
        }
      } else if (!right_q.empty() && !ferry.is_on_left) {
        while (ferry.cars_now.size() < ferry.max_cars && !right_q.empty()) {
          ferry.cars_now.push_back(right_q.front());
          right_q.pop();
        }
      } else {
        ferry.timer += ferry.time_to_cross;
        ferry.is_on_left = !ferry.is_on_left;
        continue;
      }

      ferry.timer += ferry.time_to_cross;

      for (auto car : ferry.cars_now) {
        car->finish_time = ferry.timer;
      }
      ferry.cars_now.clear();

      ferry.is_on_left = !ferry.is_on_left;
    }

    for (auto& car : cars) {
      cout << car.finish_time << '\n';
    }
  }
}