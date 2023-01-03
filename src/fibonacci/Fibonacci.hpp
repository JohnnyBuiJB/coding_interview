#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int fibonacci(int n) {
        mnCalls++;
        cout << "n = " << n << endl;
        
        return mIterFibo(n);
    }

    int getNumCalls(void) {
        return mnCalls;
    }

private:
    unordered_map<int,int> mMap;
    int mnCalls = 0;

    int mRecFibo(int n) {
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        if (!mMap.count(n)) {
            mMap[n] = mRecFibo(n - 1) + mRecFibo(n - 2);
        }

        return mMap[n];
    }

    int mIterFibo(int n) {
        mMap[0] = 0;
        mMap[1] = 1;

        for (int i = 2; i <= n; i++) {
            mMap[i] = mMap[i - 1] + mMap[i - 2];
        }

        return mMap[n];
    }
};
