#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>

// processing

bool is_leap(int year) {
  return year % 4 == 0 and (year % 100 != 0 or year % 400 == 0);
}

vi MONTH_DAYS_NORM = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vi MONTH_DAYS_LEAP = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int days_in_month(int month, bool is_leap) {
  return is_leap ? MONTH_DAYS_LEAP[month - 1] : MONTH_DAYS_NORM[month - 1];
}

// convert to offset

int year2offset(int year) {
  int offset = 0;

  for (int i = 1998; i < year; ++i) {
    offset += is_leap(i) ? 366 : 365;
  }

  return offset;
}

int month2offset(int month, bool is_leap) {
  int offset = 0;

  for (int i = 1; i < month; ++i) {
    offset += days_in_month(i, is_leap);
  }

  return offset;
}

int day2offset(int day) {
  return day;
}

// convert from offset

int offset2year(int offset) {
  int year = 1998;

  while (true) {
    int days = is_leap(year) ? 366 : 365;

    if (offset - days <= 0) {
      break;
    }

    year += 1;
    offset -= days;
  }

  return year;
}

int offset2month(int offset, bool is_leap) {
  int month = 1;

  while (true) {
    int days = days_in_month(month, is_leap);

    if (offset - days <= 0) {
      break;
    }

    month += 1;
    offset -= days;
  }

  return month;
}

int offset2day(int offset) {
  return offset;
}

int main() {
  while (true) {
    int delta, day, month, year;
    cin >> delta >> day >> month >> year;

    if (day == 0) {
      break;
    }

    int offset = delta;
    offset += year2offset(year);
    offset += month2offset(month, is_leap(year));
    offset += day2offset(day);

    int new_year = offset2year(offset);
    offset -= year2offset(new_year);
    int new_month = offset2month(offset, is_leap(new_year));
    offset -= month2offset(new_month, is_leap(new_year));
    int new_day = offset2day(offset);

    cout << new_day << ' ' << new_month << ' ' << new_year << '\n';
  }
}
