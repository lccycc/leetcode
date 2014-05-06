/*
class Solution {
public:
    void f(vector<int> &v, TreeNode *root){
        if (root == NULL) return ;
        f(v, root->left);
        f(v, root->right);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        f(v, root);
        return v;
    }
};
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> p;
        stack<int> s;
        vector<int> v;
        if (root == NULL) return v;
        p.push(root);
        s.push(0);
        while (p.size()){
            if (s.top() == 2){
                s.pop();
                v.push_back(p.top()->val);
                p.pop();
            }else if (s.top() == 1){
                s.top() = 2;
                if (p.top()->right) {
                    s.push(0);
                    p.push(p.top()->right);
                }
            }else{
                s.top() = 1;
                if (p.top()->left) {
                    s.push(0);
                    p.push(p.top()->left);
                }
            }
        }
        return v;
    }
};
