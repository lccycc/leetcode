class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<TreeNode *> p[2];
        int pnt = 0;
        vector<vector<int> > res;
        if (root == NULL) return res;
        p[0].push_back(root);
        while (p[pnt].size()){
            res.push_back(vector<int>());
            for (int i = 0; i<p[pnt].size(); i++){
                res.back().push_back(p[pnt][i]->val);
            }

            p[pnt^1].clear();
            for (int i = 0; i<p[pnt].size(); i++){
                if (p[pnt][i]->left){
                    p[pnt^1].push_back(p[pnt][i]->left);
                }
                if (p[pnt][i]->right){
                    p[pnt^1].push_back(p[pnt][i]->right);
                }
            }
            pnt^=1;
        }
        for (int l = 0, r = res.size()-1; l<r; l++, r--){
            swap(res[l], res[r]);
        }
        return res;
    }
};
