class Solution {
public:
    int tot;
    void dfs(TreeNode *root, int s){
        if (root == NULL) return ;
        s = s*10 + root->val;
        if (root->left == NULL && root->right == NULL){
            tot += s;
        }else{
            dfs(root->left, s);
            dfs(root->right, s);
        }
    }
    int sumNumbers(TreeNode *root) {
        tot = 0;
        dfs(root, 0);
        return tot;
    }
};


