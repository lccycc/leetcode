class Solution {
public:
    vector<int> s;
    vector<vector<int> > res;
    void dfs(TreeNode *root, int sum){
        if (root == NULL) return ;
        s.push_back(root->val);
        sum -= root->val;
        if (root->left == NULL && root->right == NULL){
            if (sum == 0){
                res.push_back(s);
            }
        }else{
            dfs(root->left, sum);
            dfs(root->right, sum);
        }
        s.resize(s.size()-1);
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        s.clear();
        res.clear();
        if (root ==NULL) return res;
        dfs(root, sum);
        return res;
    }
};
