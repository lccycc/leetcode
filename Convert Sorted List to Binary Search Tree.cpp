class Solution {
public:
    TreeNode *dfs(int lev, int kth, int maxlev, int base, ListNode *&pt){
        if (lev > maxlev) return NULL;
        if (lev == maxlev && kth > base) return NULL; 
        TreeNode *l = dfs(lev+1, kth<<1, maxlev, base, pt);
        TreeNode *node = new TreeNode(pt->val);
        pt = pt->next;
        node->left = l;
        node->right = dfs(lev+1, (kth<<1)+1, maxlev, base, pt);
        return node;
    }   
    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0;
        for (ListNode *p = head; p; p = p->next){
            n++;
        }
        if (n == 0) return NULL;
        int k = 1;
        while ((1<<k) < n+1){
            k++;
        }
        int m = (1<<k)-1;
        int base = (1<<(k-1)) - (m-n) - 1;
        return dfs(1, 0, k, base, head);
    }
};
