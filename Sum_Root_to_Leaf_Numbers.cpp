class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
    void dfs(TreeNode *root, int ct, int &sum){
        if (root == NULL){
            return ;
        }
        ct = ct*10 + root->val;
        if (root->left == NULL && root->right == NULL){
            sum += ct;
        }
        dfs(root->left, ct, sum);
        dfs(root->right, ct, sum);
    }
};
