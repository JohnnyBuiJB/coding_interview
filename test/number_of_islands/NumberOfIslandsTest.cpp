#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "CppUTest/TestHarness.h"


#undef new
#include <new>

using namespace std;

extern int numIslands(vector<vector <char> >& grid);

TEST_GROUP(numIslands) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(numIslands, TC001) {
    auto in = vector< vector <char> > {
        vector <char>{'1','1','1','1','0'},
        vector <char>{'1','1','0','1','0'},
        vector <char>{'1','1','0','0','0'},
        vector <char>{'0','0','0','0','0'}
    };
    int exp = 1;

    auto act = numIslands(in);
    CHECK_EQUAL(exp, act);
}

TEST(numIslands, TC002) {
    auto in = vector< vector <char> > {
        vector <char>{'1','1','0','0','0'},
        vector <char>{'1','1','0','0','0'},
        vector <char>{'0','0','1','0','0'},
        vector <char>{'0','0','0','1','1'}
    };
    int exp = 3;

    auto act = numIslands(in);
    CHECK_EQUAL(exp, act);
}

TEST(numIslands, TC003) {
    auto in = vector< vector <char> > {
        vector <char>{'1','0','1','1','1'},
        vector <char>{'1','0','1','0','1'},
        vector <char>{'1','1','1','0','1'}
    };
    int exp = 1;

    auto act = numIslands(in);
    CHECK_EQUAL(exp, act);
}