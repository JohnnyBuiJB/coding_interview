#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include <random>

#include "perf.hpp"

#include "ReverseArray.hpp"

constexpr int knTries = 1000;

#ifndef NUM_ELEMENT
    #define NUM_ELEMENT 128
#endif

int main() {
    Timer<std::chrono::nanoseconds, std::chrono::steady_clock> clock; // Timer<nanoseconds, steady_clock>
    
    // First create an instance of an engine.
    std::random_device rnd_device;
    // Specify the engine and distribution.
    std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    std::uniform_int_distribution<int> dist {1, 52};
    
    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };

    std::vector<int> nums = {100,1000,10000,100000,1000000};

    for (const auto& n : nums) {
        double min_time = std::numeric_limits<double>::max();
        
        // Prepare data
        std::vector<int> in(n);
        std::generate(std::begin(in), std::end(in), gen);

        for (int i = 0; i < knTries; i++) {
            clock.tick();

            reverse_array(in);

            clock.tock();

            auto time = clock.get_elapse_time();

            if (time < min_time) {
                min_time = time;
            }
        }
        
        std::cout << n << ",";
        std::cout << std::to_string(min_time) << std::endl;
    }

    

    

    return 0;
}
