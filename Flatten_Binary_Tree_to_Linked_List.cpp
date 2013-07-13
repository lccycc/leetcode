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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        dfs(root);
        
    }
    TreeNode *dfs(TreeNode *root){
        if (root == NULL){
            return NULL;
        }
        TreeNode *l, *r;
        l = dfs(root->left);
        r = dfs(root->right);
        if (l == NULL && r == NULL){
            return root;
        }else
        if (r == NULL){
            root->right = root->left;
            root->left = NULL;
            return l;
        }else
        if (l == NULL){
            return r;
        }else{
            l->right = root->right;
            root->right = root->left;
            root->left = NULL;
            return r;
        }
    }
};
