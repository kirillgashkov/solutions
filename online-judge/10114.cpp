#include <iostream>
#include <unordered_map>

using namespace std;

float calculate_months(int duration_months,
                       float down_payment,
                       float amount_loan,
                       int depr_count) {
  float amount_with_depr = amount_loan + down_payment;
  float amount_with_paid = amount_loan;
  float monthly_pay = amount_loan / duration_months;

  unordered_map<int, float> inv_deprs;
  for (int i = 0; i < depr_count; ++i) {
    int depr_month;
    float depr;
    cin >> depr_month >> depr;
    inv_deprs[depr_month] = 1.0 - depr;
  }

  float inv_derp;
  for (int current_month = 0; current_month <= duration_months;
       ++current_month) {
    if (inv_deprs.count(current_month)) {
      inv_derp = inv_deprs[current_month];
    }
    amount_with_depr *= inv_derp;
    if (amount_with_paid < amount_with_depr) {
      return current_month;
    }
    amount_with_paid -= monthly_pay;
  }

  return -1;
}

int main() {
  int duration_months;
  float down_payment;
  float amount_loan;
  int depr_count;

  cin >> duration_months >> down_payment >> amount_loan >> depr_count;
  while (duration_months > 0) {
    const float months_needed = calculate_months(duration_months, down_payment,
                                                 amount_loan, depr_count);
    if (months_needed == 1) {
      cout << months_needed << " month\n";
    } else {
      cout << months_needed << " months\n";
    }
    cin >> duration_months >> down_payment >> amount_loan >> depr_count;
  }
}
