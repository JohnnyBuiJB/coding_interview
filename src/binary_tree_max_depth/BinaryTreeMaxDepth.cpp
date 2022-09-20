#include "Tree.hpp"

using namespace std;

int maxDepth(BinTreeNode* root) {
    if (!root) {
        return 0;
    }
    
    if (!root->left && !root->right) {
        return 1;
    }
    
    return (1 + max(maxDepth(root->left), maxDepth(root->right)));
}
