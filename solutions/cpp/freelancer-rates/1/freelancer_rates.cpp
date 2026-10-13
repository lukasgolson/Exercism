// INFO: Headers from the standard library should be inserted at the top via
// #include <LIBRARY_NAME>
#include <cmath> 

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    return 8 * hourly_rate;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    return before_discount * ((100 - discount) / 100);
}


double discounted_monthly_rate(double hourly_rate, double discount) {
    double before_discount = daily_rate(hourly_rate) * 22;
    double discounted = apply_discount(before_discount, discount);
    return discounted;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    double discounted = discounted_monthly_rate(hourly_rate, discount);
    return (int)std::ceil(discounted); 
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    double total_cost = discounted_monthly_rate(hourly_rate, discount);

    double fraction_of_cost = budget / total_cost;
    double days = fraction_of_cost * 22;
    
    return (int)std::floor(days);
}
