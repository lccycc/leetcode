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
    int maxPathSum(TreeNode *root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode* root, int &res){
        if (root == NULL){
            return 0;
        }
        int a = root->val;
        int b = dfs(root->left, res);
        int c = dfs(root->right, res);
        res = max(a, res);
        res = max(a+b, res);
        res = max(a+c, res);
        res = max(a+b+c, res);
        return a + max(0, max(b,c));
    }
};
