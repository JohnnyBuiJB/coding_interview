#include "Tree.hpp"

using namespace std;

bool isSameTree(BinTreeNode* p, BinTreeNode* q) {
    // Input check
    if (!p && !q) {
        return true;
    } else if ((p && !q) || (!p && q)) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }
    
    return (isSameTree(p->left, q->left) 
        && isSameTree(p->right, q->right));
}
