#include <string>
#include <vector>

using namespace std;

enum Order {
    PreOrder = 0,
    InOrder,
    PostOrder,
};

struct BinTreeNode {
    int val;
    BinTreeNode *left;
    BinTreeNode *right;
    
    BinTreeNode() : val(0), left(nullptr), right(nullptr) {}
    
    BinTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
    BinTreeNode(int x, BinTreeNode *left, BinTreeNode *right) : val(x), 
        left(left), right(right) {}
};

BinTreeNode* buildTree(vector<int>& nodes, Order ord);
// void inorderTraverse(vector<int>& nodes, BinTreeNode* root);
void preorderTraverse(vector<int>& nodes, BinTreeNode* root);
// void postorderTraverse(vector<int>& nodes, BinTreeNode* root);

void delete_tree(BinTreeNode* root);