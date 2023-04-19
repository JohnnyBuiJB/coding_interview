#include <vector>
#include <algorithm>

class Solution {
public:
    int sampleCode(void) {
        return 1;
    }
};

void heapSort(std::vector<int>& vIn) {
    std::make_heap(vIn.begin(), vIn.end());

    
}

// Implement heap sort using std library. It should take O(nlogn) time and O(1)
// space.
// https://en.cppreference.com/w/cpp/algorithm/make_heap
