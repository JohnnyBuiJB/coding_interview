#include <iostream>
#include <string>
#include <cstdint>
#include <limits>

#include "perf.hpp"

constexpr int knTries = 100;

int main ()
{
    Timer<std::chrono::nanoseconds, std::chrono::steady_clock> clock; // Timer<milliseconds, steady_clock>
    double min_time = std::numeric_limits<double>::max();
    

    for (int i = 0; i < knTries; i++) {
        clock.tick();

        /* code you want to measure */
        std::string str="We think in generalities, but we live in details.";
                                                // (quoting Alfred N. Whitehead)

        std::string str2 = str.substr (3,5);     // "think"

        std::size_t pos = str.find("live");      // position of "live" in str

        std::string str3 = str.substr (pos);     // get from "live" to the end

        clock.tock();

        auto time = clock.get_elapse_time();

        if (time < min_time) {
            min_time = time;
        }
    }

    std::cout << std::to_string(min_time) << std::endl;

    return 0;
}