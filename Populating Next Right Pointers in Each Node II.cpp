class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return ;
        TreeLinkNode *t = root;
        while (t != NULL){
            TreeLinkNode *nexthead = NULL, *last = NULL;
            for (TreeLinkNode *p = t; p != NULL; p = p->next){
                if (p->left){
                    if (nexthead == NULL){
                        last = nexthead = p->left;
                    }else{
                        last = last->next = p->left;
                    }
                }
                if (p->right){
                    if (nexthead == NULL){
                        last = nexthead = p->right;
                    }else{
                        last = last->next = p->right;
                    }
                }
            }
            t = nexthead;
        }
    }
};

