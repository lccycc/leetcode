class Solution {
public:
    TreeNode *dfs(TreeNode *root){
        if (root == NULL) return NULL;
        if (root->left == NULL && root->right == NULL){
            return root;
        }
        if (root->left == NULL){
            return dfs(root->right);
        }
        TreeNode *llast = dfs(root->left);
        if (root->right == NULL){
            root->right = root->left;
            root->left = NULL;
            return llast;
        }
        TreeNode *rlast = dfs(root->right);
        llast->right = root->right;
        root->right = root->left;
        root->left = NULL;
        return rlast;
    }
    void flatten(TreeNode *root) {
        dfs(root);
    }
};
