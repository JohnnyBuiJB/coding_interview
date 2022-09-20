#include <string>
#include <vector>

using namespace std;

enum Order {
    PreOrder = 0,
    InOrder,
    PostOrder,
};

constexpr int kNullNode = -1;

// Note: Tree only accepts non-negative values
struct BinTreeNode {
    int val;
    BinTreeNode *left;
    BinTreeNode *right;
    
    BinTreeNode() : val(0), left(nullptr), right(nullptr) {}
    
    BinTreeNode(int x) : left(nullptr), right(nullptr) {
        if (x >= 0) {
            val = x;
        } else {
            val = kNullNode;
        }
    }
    
    BinTreeNode(int x, BinTreeNode *left, BinTreeNode *right) {
        if (x >= 0) {
            val = x;
            this->left = left;
            this->right = right;
        } else {
            val = kNullNode;
        }
    }
};

BinTreeNode* buildTree(vector<int>& nodes, Order ord);
// void inorderTraverse(vector<int>& nodes, BinTreeNode* root);
void preorderTraverse(vector<int>& nodes, BinTreeNode* root);
// void postorderTraverse(vector<int>& nodes, BinTreeNode* root);

void delete_tree(BinTreeNode* root);