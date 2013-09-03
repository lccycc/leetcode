
class Rec{
public:
    TreeNode *l, *r;
    Rec(TreeNode *L, TreeNode *R):l(L),r(R){}
    Rec(){l = r = NULL;}
};
void valid(TreeNode *&x, TreeNode *l, int sgn){
    if (l!=NULL && (x->val-l->val)*sgn<0){
        x = l;
    }
}
class Solution {
public:
    Rec errl, errr;
    TreeNode* errt;
    void recoverTree(TreeNode *root) {
        dfs(root);
        bool p1= (errl.r!=NULL && errl.r->val > errt->val);
        bool p2= (errr.l!=NULL && errr.l->val < errt->val);
        if (p1 && p2){
            swap(errl.r->val, errr.l->val);
        }else if (p1){
            swap(errt->val, errl.r->val);
        }else{
            swap(errt->val, errr.l->val);
        }
        
    }
    Rec dfs(TreeNode *t){
        if (t == NULL){
            return Rec();
        }
        Rec lt = dfs(t->left), rt = dfs(t->right);
        Rec x(t, t);
        valid(x.l, lt.l, -1);
        valid(x.l, rt.l, -1);
        valid(x.r, lt.r, 1);
        valid(x.r, rt.r, 1);
        if (lt.r!=NULL && t->val < lt.r->val || rt.l!=NULL && t->val > rt.l->val){
            errl = lt;
            errr = rt;
            errt = t;
        }
        return x;
    }
};
