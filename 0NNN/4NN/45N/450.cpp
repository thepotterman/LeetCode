/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) {
            return nullptr;
        }
        if(root->val == key) {
            if(root->left) {
                if(root->right) {
                    moveLeftToRight(root->left, root->right);
                    root = root->right;
                    return root;
                }
                return root->left;
            } else if(root->right) {
                return root->right;
            }
            return nullptr;
        }
        TreeNode* parent = findParentOfKey(root, key);
        if(!parent) {
            return root;
        }
        if(parent->left && parent->left->val == key) {
            parent->left = deleteNode(parent->left, key);
        } else {
            parent->right = deleteNode(parent->right, key);
        }
        return root;
    }
    void moveLeftToRight(TreeNode* left, TreeNode* right) {
        if(!right) {
            right = left;
            return;
        }
        if(!right->left) {
            right->left = left;
            left = nullptr;
            return;
        }
        moveLeftToRight(left, right->left);
    }
    TreeNode* findParentOfKey(TreeNode* root, int key) {
        if(!root) {
            return nullptr;
        }
        if(root->val > key) {
            if(!root->left) {
                return nullptr;
            }
            if(root->left->val == key) {
                return root;
            }
            return findParentOfKey(root->left, key);
        }
        if(!root->right) {
            return nullptr;
        }
        if(root->right->val == key) {
            return root;
        }
        return findParentOfKey(root->right, key);
    }
};





















