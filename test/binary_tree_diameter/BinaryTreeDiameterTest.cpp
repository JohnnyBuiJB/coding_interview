#include <iostream>
#include <string>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "Tree.hpp"


#undef new
#include <new>

using namespace std;

extern int diameterOfBinaryTree(BinTreeNode* root);

TEST_GROUP(diameterOfBinaryTree) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(diameterOfBinaryTree, TC001) {
    vector<int> preorder = {1,2,3,4,5};
    auto exp = 3;

    auto tree = buildTree(preorder, Order::PreOrder);

    auto act = diameterOfBinaryTree(tree);
    CHECK(act == exp);

    delete_tree(tree);
}

TEST(diameterOfBinaryTree, TC002) {
    vector<int> preorder = {1,2};
    auto exp = 1;

    auto tree = buildTree(preorder, Order::PreOrder);

    auto act = diameterOfBinaryTree(tree);
    CHECK(act == exp);

    delete_tree(tree);
}
