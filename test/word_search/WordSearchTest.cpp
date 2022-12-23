#include <iostream>
#include <vector>
#include <string>

#include "CppUTest/TestHarness.h"
#include "WordSearch.hpp"

#undef new
#include <new>

using namespace std;

TEST_GROUP(WordSearch) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(WordSearch, TC001) {
    vector<vector<char> > board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "SEE";
    
    auto solution = Solution();

    bool exp = true;

    auto act = solution.exist(board, word);

    CHECK_EQUAL(exp, act);
}

TEST(WordSearch, TC002) {
    vector<vector<char> > board = {
        {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}
    };

    string word = "ABCB";
    
    auto solution = Solution();

    bool exp = false;

    auto act = solution.exist(board, word);

    CHECK_EQUAL(exp, act);
}
