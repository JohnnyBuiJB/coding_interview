#include "AirlineTicketEstimate.hpp"

class UnitedAirline : public Airline {
public:
    float CalculateCost(float distance, string seat_type) override {
//         - United charges $0.75/mile
//    + OperatingCost
//    + $0.10/mile for Premium seats

// Operating Costs:

//  - Economy:  No charge
//  - Premium:  $25
//  - Business: $50 + $0.25/mile

        float operating_cost = 0;
        float fly_cost = 0;
        if (seat_type == "Premium") {
            fly_cost = distance * 0.1;
            operating_cost = 25;
        } else if (seat_type == "Economy") {
            fly_cost = distance * 0.75;
            operating_cost = 0;
        } else if (seat_type == "Business") {
            fly_cost = distance * 0.75;
            operating_cost = 50 + 0.25 * distance;
        }

        return operating_cost + fly_cost;
    };
};

class SouthwestAirline : public Airline {
public:
    float CalculateCost(float distance, string seat_type) override {

        // - Southwest charges $1.00/mile
        float operating_cost = 0;
        float fly_cost = distance;
        if (seat_type == "Premium") {
            operating_cost = 25;
        } else if (seat_type == "Economy") {
            operating_cost = 0;
        } else if (seat_type == "Business") {
            operating_cost = 50 + 0.25 * distance;
        }

        return operating_cost + fly_cost;
    };
};

class DeltaAirline : public Airline{
public:
    float CalculateCost(float distance, string seat_type) override {
        float operating_cost = 0;
        float fly_cost = distance * 0.5;
        if (seat_type == "Premium") {
            operating_cost = 25;
        } else if (seat_type == "Economy") {
            operating_cost = 0;
        } else if (seat_type == "Business") {
            operating_cost = 50 + 0.25 * distance;
        }

        return operating_cost + fly_cost;
    };
};

class LuigiAirline : public Airline{
public:
    float CalculateCost(float distance, string seat_type) override {
        // - LuigiAir charges $100 or 2 * OperatingCost, whichever is higher
        float operating_cost = 0;
        if (seat_type == "Premium") {
            operating_cost = 25;
        } else if (seat_type == "Economy") {
            operating_cost = 0;
        } else if (seat_type == "Business") {
            operating_cost = 50 + 0.25 * distance;
        }

        operating_cost *= 2;

        return (operating_cost > 100) ? operating_cost : 100;
    };
};