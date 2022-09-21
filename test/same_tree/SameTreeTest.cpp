#include <iostream>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "Tree.hpp"

#undef new
#include <new>

using namespace std;

extern bool isSameTree(BinTreeNode* p, BinTreeNode* q);

TEST_GROUP(isSameTree) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(isSameTree, TC001) {
    vector<int> in1 = {1,2,3};
    vector<int> in2 = {1,2,3};
    bool exp = true;

    auto tree1 = buildTree(in1, Order::PreOrder);
    auto tree2 = buildTree(in2, Order::PreOrder);

    auto act = isSameTree(tree1, tree2);

    CHECK(act == exp);

    delete_tree(tree1);
    delete_tree(tree2);
}

TEST(isSameTree, TC002) {
    vector<int> in1 = {1,2};
    vector<int> in2 = {1,kNullNode,2};
    bool exp = false;

    auto tree1 = buildTree(in1, Order::PreOrder);
    auto tree2 = buildTree(in2, Order::PreOrder);

    auto act = isSameTree(tree1, tree2);

    CHECK(act == exp);

    delete_tree(tree1);
    delete_tree(tree2);
}

TEST(isSameTree, TC003) {
    vector<int> in1 = {1,2,1};
    vector<int> in2 = {1,1,2};
    bool exp = false;

    auto tree1 = buildTree(in1, Order::PreOrder);
    auto tree2 = buildTree(in2, Order::PreOrder);

    auto act = isSameTree(tree1, tree2);

    CHECK(act == exp);

    delete_tree(tree1);
    delete_tree(tree2);
}