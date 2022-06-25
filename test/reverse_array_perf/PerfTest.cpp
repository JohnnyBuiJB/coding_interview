#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "perf.hpp"

#include "ReverseArray.hpp"

constexpr int knTries = 1000;

int main() {
    Timer<std::chrono::nanoseconds, std::chrono::steady_clock> clock; // Timer<nanoseconds, steady_clock>
    double min_time = std::numeric_limits<double>::max();
    
    // Prepare data
    std::vector<int> in(10000);

    for (int i = 0; i < knTries; i++) {
        clock.tick();

        reverse_array(in);

        clock.tock();

        auto time = clock.get_elapse_time();

        if (time < min_time) {
            min_time = time;
        }
    }

    std::cout << std::to_string(min_time) << " ns" << std::endl;

    return 0;
}
