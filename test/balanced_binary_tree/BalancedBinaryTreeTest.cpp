#include <iostream>
#include <string>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "Tree.hpp"


#undef new
#include <new>

using namespace std;

extern int isBalanced(BinTreeNode* root);

TEST_GROUP(isBalanced) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(isBalanced, TC001) {
    vector<int> preorder = {3,9,20,kNullNode,kNullNode,15,7};
    auto exp = true;

    auto tree = buildTree(preorder, Order::PreOrder);

    auto act = isBalanced(tree);
    CHECK(act == exp);

    delete_tree(tree);
}

TEST(isBalanced, TC002) {
    vector<int> preorder = {1,2,2,3,3,kNullNode,kNullNode,4,4};
    auto exp = false;

    auto tree = buildTree(preorder, Order::PreOrder);

    auto act = isBalanced(tree);
    CHECK(act == exp);

    delete_tree(tree);
}