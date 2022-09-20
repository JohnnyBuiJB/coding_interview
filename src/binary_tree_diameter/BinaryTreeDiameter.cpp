#include "Tree.hpp"

using namespace std;

static int sDiameter = 0;

// This calculate both tree heights and update max diameter
static int dfs(BinTreeNode* root) {
    if (!root) {
        return -1;
    }
    
    auto l_h = dfs(root->left);
    auto r_h = dfs(root->right);
    auto w = l_h + r_h + 2;
    
    if (w > sDiameter) {
        sDiameter = w;
    }
    
    return 1 + max(l_h, r_h);
}

/**
 * \Trick   Use a global variable to store diameter to grant access to dfs so 
 *          that it can update max diameter and calculate the tree height at the 
 *          same time. This reduce the recursive calls significantly, which 
 *          results in linear running time.
 * \Time    O(n)
 * \Space   O(n)
 * \Ref     Neetcode
 */
int diameterOfBinaryTree(BinTreeNode* root) {
    sDiameter = 0;
    
    dfs(root);
    
    return sDiameter;
}
