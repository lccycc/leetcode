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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (root == NULL) return res;
        vector<TreeNode*> p[2];
        p[0].push_back(root);
        int pnt = 0;
        while (p[pnt].size()){
            res.push_back(vector<int>());
            if (pnt == 0){
                for (int i = 0; i<p[pnt].size(); i++){
                    res.back().push_back(p[pnt][i]->val);
                }
            }else{
                for (int i = p[pnt].size()-1; i>=0; i--){
                    res.back().push_back(p[pnt][i]->val);
                }
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
            pnt ^= 1;
        }
        return res;
    }
};
