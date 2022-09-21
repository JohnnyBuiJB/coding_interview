#include "Tree.hpp"

static int sSubRootHeight = 0;
static BinTreeNode* sSubRoot = nullptr;
static bool sIsSubTree = false;

extern bool isSameTree(BinTreeNode* p, BinTreeNode* q);

static int dfs(BinTreeNode* root) {
    if (!root) {
        return 0;
    }

    auto h = 1 + max(dfs(root->left), dfs(root->right));

    if (!sIsSubTree) {
        if (h == sSubRootHeight) {
            sIsSubTree = isSameTree(root, sSubRoot);
        }
    }

    return h;
}

/**
 * \Trick   Observation 1: trees are only equal when they have the same height. 
 *          
 *          Including this to the algorithm helps avoiding checking subtrees 
 *          whose heights are different from the subroot, which avoid lots of 
 *          redundant checking.
 * 
 * \Time    O(n), with n is the number of node of the tree and h is the height 
 *          of the subroot.
 * 
 *          The worst case is when the tree is full and the subtree is 
 *          only one node. Then we have to check every leave of the tree, which 
 *          is n/2. And each check takes O(1) time because the all of the 
 *          subtrees are only one node.
 * 
 *          The cost of checking all of subtrees whose height is equal h can be 
 *          formulated as (n/2^h) x h, by the observation that the number of 
 *          nodes at height h + 1 = twice the number of nodes at height h. 
 * 
 *          Furthermore, the formulation can written as n x (h / 2^h). The 
 *          latter multiplier is a function of h and has its limit approach 0 
 *          when h approaches inf. This shows that h / 2^h = O(1), hence the 
 *          cost is O(n).
 * 
 * \Space   O(n), recursion
 * \Ref     Bui V.
 */
bool isSubtree(BinTreeNode* root, BinTreeNode* subRoot) {
    // Sanity check
    if (!root && !subRoot) {
        return true;
    }

    // Init
    sSubRoot = subRoot;
    sIsSubTree = false;

    // Find subroot's height
    sSubRootHeight = dfs(subRoot);

    // Search and test subtrees with the same height as subroot
    dfs(root);

    return sIsSubTree;
}
