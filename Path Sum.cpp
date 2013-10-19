/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL){
            return sum == root->val;
        }
        sum -= root->val;
        if (root->left){
            if (hasPathSum(root->left, sum)) return true;
        }
        if (root->right){
            if (hasPathSum(root->right, sum)) return true;
        }
        return false;
    }
};
