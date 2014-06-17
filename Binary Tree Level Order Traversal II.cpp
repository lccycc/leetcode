/*
    clear g  at the beginning of loop
    swap f, g at the end of loop
*/
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        vector<TreeNode*> f, g;
        if (!root) return res;
        f.push_back(root);
        while (f.size()){
            g.clear();
            res.push_back(vector<int>());
            for (TreeNode* x : f){
                res.back().push_back(x->val);
                if (x->left) g.push_back(x->left);
                if (x->right) g.push_back(x->right);
            }
            f.swap(g);
        }
        for (int l = 0, r = res.size()-1; l<r; l++, r--){
            res[l].swap(res[r]);
        }
        return res;
    }
};
