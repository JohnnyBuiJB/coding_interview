/*
You're building a tool to estimate the cost of various airplane tickets based on the airline, distance and seating class. Your tool must take in this information as a series of inputs (one ticket calculation per line of input) and produce a list of output costs.

Each airline contains its own cost requirements. Ultimately, the airline is only interested in two major components: the space (seating class) you take on the plane, and the distance you fly. You must generate ticket costs using this gathered data:

Airlines: United, Delta, Southwest, LuigiAir


total_cost = operating_cost + price

Operating Costs:

 - Economy:  No charge
 - Premium:  $25
 - Business: $50 + $0.25/mile

Per-Airline Prices:

 - Delta charges $0.50/mile
   + OperatingCost
   
 - United charges $0.75/mile
   + OperatingCost
   + $0.10/mile for Premium seats

 - Southwest charges $1.00/mile

 - LuigiAir charges $100 or 2 * OperatingCost, whichever is higher

Keep in mind that, while there are only four airlines listed above, your solution should be able to expand to dozens of individual airlines, whose ticket cost can be based on arbitrary functions of "Operating Costs", miles, and/or seating class.

You can assume that the input will be provided as a list, and that there could be millions of elements in this list. Each element is another list that provides strings of the Airline, Distance, and Seating Class. Please review the examples below:

Example Input:
-------------------------------------------
United 150.0 Premium
Delta 60.0 Business
Southwest 1000.0 Economy
LuigiAir 50.0 Business
-------------------------------------------

Example Output:
-------------------------------------------
152.50
95.00
1000.00
125.00
-------------------------------------------

Explanation of Output:
-------------------------------------------
152.50      (150.0 * (0.75 + 0.10) + 25)
95.00       (60.0 * (0.50 + 0.25) + 50)
1000.00     (1000.0 * 1.00)
125.00      (100 <= 2 * (50 + 50 * 0.25))
-------------------------------------------


 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Airline {
public:
    virtual float CalculateCost(float distance, string seat_type) = 0;
};

// class UnitedAirline : public Airline {
// public:
//     float CalculateCost(float distance, string seat_type) override {
// //         - United charges $0.75/mile
// //    + OperatingCost
// //    + $0.10/mile for Premium seats

// // Operating Costs:

// //  - Economy:  No charge
// //  - Premium:  $25
// //  - Business: $50 + $0.25/mile

//         float operating_cost = 0;
//         float fly_cost = 0;
//         if (seat_type == "Premium") {
//             fly_cost = distance * 0.1;
//             operating_cost = 25;
//         } else if (seat_type == "Economy") {
//             fly_cost = distance * 0.75;
//             operating_cost = 0;
//         } else if (seat_type == "Business") {
//             fly_cost = distance * 0.75;
//             operating_cost = 50 + 0.25 * distance;
//         }

//         return operating_cost + fly_cost;
//     };
// };

// class SouthwestAirline : public Airline {
// public:
//     float CalculateCost(float distance, string seat_type) override {

//         // - Southwest charges $1.00/mile
//         float operating_cost = 0;
//         float fly_cost = distance;
//         if (seat_type == "Premium") {
//             operating_cost = 25;
//         } else if (seat_type == "Economy") {
//             operating_cost = 0;
//         } else if (seat_type == "Business") {
//             operating_cost = 50 + 0.25 * distance;
//         }

//         return operating_cost + fly_cost;
//     };
// };

// class DeltaAirline : public Airline{
// public:
//     float CalculateCost(float distance, string seat_type) override {
//         float operating_cost = 0;
//         float fly_cost = distance * 0.5;
//         if (seat_type == "Premium") {
//             operating_cost = 25;
//         } else if (seat_type == "Economy") {
//             operating_cost = 0;
//         } else if (seat_type == "Business") {
//             operating_cost = 50 + 0.25 * distance;
//         }

//         return operating_cost + fly_cost;
//     };
// };

// class LuigiAirline : public Airline{
// public:
//     float CalculateCost(float distance, string seat_type) override {
//         // - LuigiAir charges $100 or 2 * OperatingCost, whichever is higher
//         float operating_cost = 0;
//         if (seat_type == "Premium") {
//             operating_cost = 25;
//         } else if (seat_type == "Economy") {
//             operating_cost = 0;
//         } else if (seat_type == "Business") {
//             operating_cost = 50 + 0.25 * distance;
//         }

//         operating_cost *= 2;

//         return (operating_cost > 100) ? operating_cost : 100;
//     };
// };

class AirlinePriceEstimater {
public:
    AirlinePriceEstimater() {
        airlines_["United"] = new UnitedAirline();
        airlines_["Southwest"] = new SouthwestAirline();
        airlines_["Delta"] = new DeltaAirline();
        airlines_["LuigiAir"] = new UnitedAirline();
    }

    ~AirlinePriceEstimater() {
        for (auto& airline : airlines_) {
            delete airline;
        }
    }

    void estimate(vector<vector<string> > input) {
        // vector<float> out;

        for (auto& in : input) {
            auto airline_name = in[0];
            auto num_miles = stof(in[1]);
            auto seat_type = in[2];

            Airline *airline = airlines_[airline_name];
            auto cost = airline->CalculateCost(num_miles, seat_type);

            cout << cost << endl;
        }

        // return out;
    }
private:
    unordered_map<string, *Airline> airlines_;
};

