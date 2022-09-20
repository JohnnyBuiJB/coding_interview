#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "CppUTest/TestHarness.h"
#include "Tree.hpp"

#undef new
#include <new>

using namespace std;

extern int maxDepth(BinTreeNode* root);

TEST_GROUP(maxDepth) {
    void setup() {
        // TBD
    }

    void teardown() {
        // TBD
    }
};

TEST(maxDepth, TC001) {
    vector<int> preorder = {3,9,20,kNullNode,kNullNode,15,7};
    auto exp = 3;
    auto tree = buildTree(preorder, Order::PreOrder);

    auto act = maxDepth(tree);

    CHECK(act == exp);

    delete_tree(tree);
}
