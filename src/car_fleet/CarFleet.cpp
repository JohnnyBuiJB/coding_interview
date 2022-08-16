#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <cstdint>

using namespace std;

namespace {
struct Car {
    int p;  // Position
    int v;  // Velocity

    Car(int pos, int speed) : p(pos), v(speed) {
        // Do nothing
    }
};

bool comp(const Car& c1, const Car& c2) {
    if (c1.p < c2.p) {
        return true;
    } else {
        return false;
    }
}
}

/**
 * \Trick   Observation 1: if a car catch up with a car fleet, the entire car 
 *          fleet can be represented by the slowest car in the fleet, which is 
 *          also the first car of the fleet. Note that the slowest car means one 
 *          that reaches the target last, not the one with the smallest speed. 
 *          Because in some cases, cars with higher speeds but start at 
 *          positions too far from the target still reach the target after ones 
 *          with smaller speeds.
 * 
 *          Observation 2: when checking if a car can catch up with the fleets 
 *          ahead, we only need to check the next fleet. because it will be 
 *          slowed down by the next fleet (in case it can catch up) and never be 
 *          able to catch the other fleets ahead.
 * \Time    O(nlogn), dominated by sorting
 * \Space   O(n), for the stack for fleets
 * \Ref     Neetcode
 */
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<Car> cars;
    for (auto p_it = position.begin(), s_it = speed.begin(); p_it != position.end(); 
        p_it++, s_it++) {
        cars.push_back(Car(*p_it, *s_it));
    }

    // Sort based on position
    sort(cars.begin(), cars.end(), comp);

    
    // Monotonic decreasing stack of fleets; the fleet on top of the stack is 
    // the last
    stack<Car> fleets;
    
    // Check if each car can catch up with the ahead fleet
    for (auto c_rit = cars.rbegin(); c_rit != cars.rend(); c_rit++) {
        if (fleets.empty()) {
            fleets.push(*c_rit);
        } else {
            auto last_car = fleets.top();
            
            // t1 = s1/v1 > t2 = s2/v2 <=> p1 = s1*v2 > p2 = s2*v1
            // Avoid floating point arithmetic
            int64_t p1 = (int64_t)(target - c_rit->p) * last_car.v;
            int64_t p2 = (int64_t)(target - last_car.p) * c_rit->v;
            if (p1 > p2) {
                // New fleet
                fleets.push(*c_rit);
            }
        }
    }

    return fleets.size();
}
