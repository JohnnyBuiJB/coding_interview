#include "Tree.hpp"

using namespace std;

static bool is_balanced = true;

static int dfs(BinTreeNode* root) {
    if (!root) {
        return 0;
    }
    
    int l_h = dfs(root->left);
    int r_h = dfs(root->right);
    int h_dif = l_h - r_h;
    
    if (h_dif > 1 || h_dif < -1) {
        is_balanced = false;
    }

    return (1 + max(l_h, r_h));
}

/**
 * \Trick   Use dfs calculate subtrees' heights and keep track of the balance 
 *          of the trees by a global variable.
 * 
 * \Time    O(n), visit every node once
 * \Space   O(n), stack for recursive
 * \Ref     Bui V.
 */
bool isBalanced(BinTreeNode* root) {
    // Sanity check
    if (!root) {
        return true;
    }
    
    // Init
    is_balanced = true;

    dfs(root);

    return is_balanced;
}
