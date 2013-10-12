class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL) return res;
        stack<TreeNode *> s;
        TreeNode *p =root;
        while (true){
            if (p){
                s.push(p);
                p = p->left;
            }else{
                if (!s.size()) break;
                p = s.top();
                s.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
};
