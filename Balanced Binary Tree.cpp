/*
    return depth of each node
    1 if NULL, return 0
    2 get depths of two sons, judge whether they differ by more than 1
    3 return max(son_depths)+1
    There is another version: Any two LEAFs' depths differs by more than 1
    in this case, return min_depth and max_depth and judge in root
*/
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        bool res = true;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode *root, bool &res){
        if (root == NULL || !res){
            return 0;
        }
        int l = dfs(root->left, res), r = dfs(root->right, res);
        if (abs(l-r)>1){
            res = false;
            return 0;
        }
        return max(l, r)+1;
    }
};
