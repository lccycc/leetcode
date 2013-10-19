class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL){
            return 0;
        }
        int res = INT_MAX;
        dfs(root, 1, res);
        return res;
    }
    void dfs(TreeNode *root, int dp, int &res){
        if (root==NULL) return ;
        if (dp >= res){
            return ;
        }
        if (root->left == NULL && root->right == NULL){
            res = min(dp, res);
            return ;
        }
        dfs(root->left, dp+1, res);
        dfs(root->right, dp+1, res);
    }
};
