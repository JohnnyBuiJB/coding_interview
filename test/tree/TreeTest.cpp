#include <iostream>
#include <string>

#include "CppUTest/TestHarness.h"
#include "Tree.hpp"


#undef new
#include <new>

using namespace std;

TEST_GROUP(buildTree) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(buildTree, TC001) {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> act;

    auto tree = buildTree(preorder, Order::PreOrder);

    preorderTraverse(act, tree);

    CHECK(preorder == act);

    delete_tree(tree);
}

TEST(buildTree, TC002) {
    vector<int> preorder = {3,9,20,kNullNode,kNullNode,15,7};
    vector<int> exp = {3,9,20,15,7};
    vector<int> act;

    auto tree = buildTree(preorder, Order::PreOrder);

    preorderTraverse(act, tree);

    CHECK(exp == act);

    delete_tree(tree);
}
