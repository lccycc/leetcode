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
        if (root == NULL) return ;
        TreeLinkNode *l = root;
        while (l){
            TreeLinkNode *nhead = NULL, *last = NULL;
            while (l){
                if (l->left){
                    if (last == NULL){
                        nhead = last = l->left;
                    }else{
                        last = last->next = l->left;
                    }
                }
                if (l->right){
                    if (last == NULL){
                        nhead = last = l->right;
                    }else{
                        last = last->next = l->right;
                    }
                }
                l = l->next;
            }
            l = nhead;
        }
    }
};



