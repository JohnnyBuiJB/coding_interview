// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

#include "ReverseArray.hpp"

using namespace std;


void swap(std::vector<int> &rArr, uint32_t i, uint32_t j) {
    auto tmp = rArr.at(j);
    rArr.at(j) = rArr.at(i);
    rArr.at(i) = tmp;
}

void reverse_array(std::vector<int> &rArr) {
    auto n = rArr.size();
    auto mid = rArr.size() / 2;

    for (auto i = 0; i < mid; i++) {
        swap(rArr, i, n - 1 - i);
    }
}
