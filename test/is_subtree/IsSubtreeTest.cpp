#include <iostream>
#include <string>
#include <vector>

#include "CppUTest/TestHarness.h"
#include "Tree.hpp"


#undef new
#include <new>

using namespace std;

extern bool isSubtree(BinTreeNode* root, BinTreeNode* subRoot);

TEST_GROUP(isSubtree) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(isSubtree, TC001) {
    vector<int> tree_preorder = {3,4,5,1,2};
    vector<int> subtree_preorder = {4,1,2};
    auto exp = true;

    auto tree = buildTree(tree_preorder, Order::PreOrder);
    auto sub_tree = buildTree(subtree_preorder, Order::PreOrder);

    auto act = isSubtree(tree, sub_tree);
    CHECK(act == exp);

    delete_tree(tree);
    delete_tree(sub_tree);
}

TEST(isSubtree, TC002) {
    vector<int> tree_preorder = {3,4,5,
        1,2,kNullNode,kNullNode,
        kNullNode,kNullNode,0};

    vector<int> subtree_preorder = {4,1,2};
    auto exp = false;

    auto tree = buildTree(tree_preorder, Order::PreOrder);
    auto sub_tree = buildTree(subtree_preorder, Order::PreOrder);

    auto act = isSubtree(tree, sub_tree);
    CHECK(act == exp);

    delete_tree(tree);
    delete_tree(sub_tree);
}
