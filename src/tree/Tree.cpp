#include <queue>
#include <stack>
#include "Tree.hpp"
#include "LinkedList.hpp"

using namespace std;

#define RECUR_IMP   0

BinTreeNode* buildTree(vector<int>& nodes, Order ord) {
    BinTreeNode* root = nullptr;
    BinTreeNode* new_node = nullptr;
    
    if (ord == PreOrder) {
        queue<BinTreeNode**> q;

        for (auto &node : nodes) {
            new_node = new BinTreeNode(node);

            if (!root) {
                root = new_node;
            } else {
                *q.front() = new_node;
                q.pop();
            }

            q.push(&new_node->left);
            q.push(&new_node->right);
        }
    }

    return root;
}

void delete_tree(BinTreeNode* root) {
    vector<BinTreeNode* > preorder;
    preorder.push_back(root);
    size_t i = 0;
    
    while (i < preorder.size()) {
        auto node = preorder[i++];
        
        if (node->left) {
            preorder.push_back(node->left);
        }

        if (node->right) {
            preorder.push_back(node->right);
        }
    }

    for (auto rit = preorder.rbegin(); rit != preorder.rend(); ++rit) {
        delete *rit;
    }

}

// void inorderTraverse(vector<int>& nodes, BinTreeNode* root) {
// #if RECUR_IMP == 1
// /**
//  * \Trick   Using a recursive function and global variables to allow access 
//  *          between recursive calls.
//  * \Time    O(n)
//  * \Space   O(n)
//  * \Ref     Bui V.
//  */
    
// // class dfs {
// // public:
// //     dfs() {}

// // private:

// // }; 

// //     // Init nodes
// //     nodes.clear();

// //     auto dfs = [&] (BinTreeNode* root) {
// //         if (root) {
// //             dfs(root->left);
// //             nodes.push_back(root->val);
// //             dfs(root->right);
// //         }
// //     }
// #else
// /**
//  * \Trick   Use a queue or a stack to keep track of the unexhausted nodes.
//  * 
//  *          Because the expanded nodes can be anywhere in the list, using a 
//  *          doubly linked list to keep the results helps modify the result in 
//  *          O(1).
//  * \Time    O(2n), one pass through all nodes to make the doubly linked list, 
//  *          and another pass to go through the list to return the result
//  * \Space   O(n)
//  * \Ref     Bui V.
//  */
//     stack<BinTreeNode*> s;
//     s.push(root);
    

//     while(!s.empty()) {
        
//     }

// #endif
// }

void preorderTraverse(vector<int>& nodes, BinTreeNode* root) {
    queue<BinTreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        auto node = q.front();
        nodes.push_back(node->val);

        q.pop();

        if (node->left) {
            q.push(node->left);
        }
        
        if (node->right) {
            q.push(node->right);
        }
    }
}

// void postorderTraverse(vector<int>& nodes, BinTreeNode* root) {

// }
