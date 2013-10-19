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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<TreeNode*> p[2];
        vector<vector<int> > res;
        if (root == NULL) return res;
        int pnt = 0;
        p[0].push_back(root);
        while (p[pnt].size()){
            res.push_back(vector<int>());
            for (int i = 0; i<p[pnt].size();i++){
                res.back().push_back(p[pnt][i]->val);
            }
            p[pnt^1].clear();
            for (int i = 0; i<p[pnt].size();i++){
                if (p[pnt][i]->left){
                    p[pnt^1].push_back(p[pnt][i]->left);
                }
                if (p[pnt][i]->right){
                    p[pnt^1].push_back(p[pnt][i]->right);
                }
            }
            pnt ^= 1;
        }
        return res;
    }
};
