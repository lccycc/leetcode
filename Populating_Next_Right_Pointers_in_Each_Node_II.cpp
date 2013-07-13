/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL){
            return ;
        }
        TreeLinkNode *fir = NULL, *lst = NULL;
        for (TreeLinkNode* t = root; t!=NULL; t = t->next){
            if (t->left != NULL){
                if (lst != NULL){
                    lst->next = t->left;
                }
                lst = t->left;
                if (fir == NULL){
                    fir = lst;
                }
            }
            if (t->right != NULL){
                if (lst != NULL){
                    lst->next = t->right;
                }
                lst = t->right;
                if (fir == NULL){
                    fir = lst;
                }
            }
        }
        connect(fir);
    }
};
