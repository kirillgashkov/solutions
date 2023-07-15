#include <cmath>
#include <iostream>
using namespace std;

int main() {
  while (true) {
    int hours;
    int minutes;
    scanf("%d:%d", &hours, &minutes);

    if (hours == 0 and minutes == 0) {
      break;
    }

    float degrees_per_minute = 360.0 / 60;
    float degrees_per_hour = 360.0 / 12;
    float degrees_per_minute_between_hours = 30.0 / 60;

    float angle = fabs(float(hours) * degrees_per_hour +
                       float(minutes) * degrees_per_minute_between_hours -
                       float(minutes) * degrees_per_minute);

    if (angle > 180) {
      angle = 360 - angle;
    }

    printf("%.3f\n", angle);
  }
}
