#include <iostream>
#include <string>
#include <cstdint>
#include <limits>
#include <vector>
#include "CppUTest/TestHarness.h"

using namespace std;

extern bool isValidSudoku(vector<vector<char>>& board);

TEST_GROUP(func) {
    void setup() {
    }

    void teardown() {
    }
};

TEST(func, TC001) {
    // Prepare data
    vector<vector<char>> in  {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, 
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, 
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, 
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, 
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, 
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, 
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, 
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    auto ret = isValidSudoku(in);

    CHECK(ret == true);
}

TEST(func, TC002) {
    // Prepare data
    vector<vector<char>> in {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};

    auto ret = isValidSudoku(in);

    CHECK(ret == false);
}

TEST(func, TC003) {
    // Prepare data
    vector<vector<char>> in {
        {".",".",".","9",".",".",".",".","."},
        {".",".",".",".",".",".",".",".","."},
        {".",".","3",".",".",".",".",".","1"},
        {".",".",".",".",".",".",".",".","."},
        {"1",".",".",".",".",".","3",".","."},
        {".",".",".",".","2",".","6",".","."},
        {".","9",".",".",".",".",".","7","."},
        {".",".",".",".",".",".",".",".","."},
        {"8",".",".","8",".",".",".",".","."}};

    auto ret = isValidSudoku(in);

    CHECK(ret == false);
}
