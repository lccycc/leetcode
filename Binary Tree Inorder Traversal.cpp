class Inorder{
    stack<TreeNode *> s;
    TreeNode *p;
public:
    Inorder(TreeNode* root){
        p = root;
        while (!s.empty()) s.pop();
    }
    TreeNode* next(){
        TreeNode* res = NULL;
        while (!res){
            if (p == NULL){
                if (s.empty()) break;
                res = p = s.top();
                s.pop();
                p = p->right;
            }else{
                s.push(p);
                p = p->left;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        Inorder o(root);
        TreeNode *p;
        while ((p = o.next()) != NULL){
            res.push_back(p->val);
        }
        return res;
    }
};
