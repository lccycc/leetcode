class Solution {
public:
    bool dfs(TreeNode *l, TreeNode *r){
        if ((l==NULL) != (r==NULL)){
            return false;
        }
        if (l == NULL) return true;
        if (l->val != r->val) return false;
        return dfs(l->left, r->right) && dfs(l->right, r->left);
    }
    /*
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return dfs(root->left, root->right);
    }
    */
    bool isSymmetric(TreeNode *root) {
        stack<TreeNode *> s1, s2;
        stack<int> stat;
        if (root == NULL) return true;
        s1.push(root->left);
        s2.push(root->right);
        stat.push(0);
        while (s1.size()){
            if ((s1.top() == NULL)!=(s2.top()==NULL)) return false;
            if (stat.top() == 2 || s1.top() == NULL){
                stat.pop();
                s1.pop();
                s2.pop();
            }else if (stat.top() == 0){
                if (s1.top()->val != s2.top()->val) return false;
                stat.top()++;
                stat.push(0);
                s1.push(s1.top()->left);
                s2.push(s2.top()->right);
            }else if (stat.top() == 1){
                stat.top()++;
                stat.push(0);
                s1.push(s1.top()->right);
                s2.push(s2.top()->left);
            }
        }
        return true;    
    }
};
