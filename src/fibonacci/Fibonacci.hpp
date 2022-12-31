#include <unordered_map>

using namespace std;

class Solution {
public:
    int fibonacci(int n) {
        mnCalls++;
        
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        if (!mMap.count(n)) {
            mMap[n] = fibonacci(n - 1) + fibonacci(n - 2);
        }

        return mMap[n];
    }

    int getNumCalls(void) {
        return mnCalls;
    }

private:
    unordered_map<int,int> mMap;
    int mnCalls = 0;
};
