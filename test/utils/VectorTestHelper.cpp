#include "VectorTestHelper.hpp"

using namespace std;

bool equalVector(vector<vector<int> > v1, vector<vector<int> > v2) {
    bool result = false;

    for (auto& item : v1) {
        result = false;
        for (size_t i = 0; i < v2.size(); i++) {
            if (v2[i] == item) {
                v2.erase(v2.begin() + i);
                result = true;
                continue;
            }
        }
    }

    if (v2.size() != 0) {
        result = false;
    }

    return result;
}
