class Solution {
public:
    vector<int> sta;
    vector<vector<int>> res;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        res.clear();
        sta.clear();
        hasPathSum(root, sum);
        return res;
        
    }
    void hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL){
            return ;
        }
        sta.push_back(root->val);
        if (root->left == NULL && root->right == NULL){
            if (sum == root->val){
                res.push_back(sta);
            }
        }
        hasPathSum(root->left, sum - root->val);
        hasPathSum(root->right, sum - root->val);
        sta.erase(sta.begin()+(sta.size()-1));
    }
};
