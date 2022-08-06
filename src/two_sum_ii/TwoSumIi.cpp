#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> twoSumII(vector<int>& numbers, int target) {
    int l = 0;
    int r = numbers.size() - 1;
    
    // Linear search in the potential window
    while (l < r) {
        int l_val = numbers[l];
        int k = target - l_val;
        
        if (numbers[r] >= k) {
            if (numbers[r] == k) {
                return vector<int> {l + 1, r + 1};
            }
            r--;
            continue;
        }
        
        l++;
    }
    
    return vector<int> {0,0};
}
