#include "vehicle_purchase.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

namespace vehicle_purchase {
    // needs_license determines whether a license is needed to drive a type of
    // vehicle. Only "car" and "truck" require a license.
    bool needs_license(std::string kind) {
        return kind == "car" || kind == "truck";
    }

    // choose_vehicle recommends a vehicle for selection. It always recommends the
    // vehicle that comes first in lexicographical order.
    std::string choose_vehicle(std::string option1, std::string option2) {
        if (option1 < option2) {
            return option1;
        }
        return option2;
    }

    // calculate_resell_price calculates how much a vehicle can resell for at a
    // certain age.
    double calculate_resell_price(double original_price, double age) {

        if (age < 3) {
            return original_price * 0.8;
        }

        if (age > 10) {
            return original_price * 0.5;
        }

        return original_price * 0.7;


        return 0.0;
    }
} // namespace vehicle_purchase
