#include "Tree.hpp"

using namespace std;

static int sDiameter = 0;

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


int diameterOfBinaryTree(BinTreeNode* root) {
    sDiameter = 0;
    
    dfs(root);
    
    return sDiameter;
}
