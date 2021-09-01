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
    bool isValidBST(TreeNode* root) {
        if(!root) {
            return false;
        }
        if(!checkVal(root)) {
            return false;
        }
        if(!root->left && !root->right) {
            return true;
        }
        if(!root->right) {
            return checkLeft(root);
        }
        if(!root->left) {
            return checkRight(root);
        }
        return checkLeft(root) && checkRight(root);
    }
    bool checkLeft(TreeNode* root) {
        bool answer = false;
        if(!this->max || this->max > root->val) {
            optional<int> tmp = this->max;
            this->max = root->val;
            answer = isValidBST(root->left);
            this->max = tmp;
            return answer;
        }
        return isValidBST(root->left);
    }
    bool checkRight(TreeNode* root) {
        bool answer = false;
        if(!this->min || this->min < root->val) {
            optional<int> tmp = this->min;
            this->min = root->val;
            answer = isValidBST(root->right);
            this->min = tmp;
            return answer;
        }
        return isValidBST(root->right);
    }
    bool checkVal(TreeNode* root) {
        if(this->max && this->max.value() <= root->val) {
             return false;
        }
        if(this->min && this->min.value() >= root->val) {
             return false;
        }
        return true;
    }
    optional<int> max = nullopt;
    optional<int> min = nullopt;
};
