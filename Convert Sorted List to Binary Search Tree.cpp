class Solution {
public:
    TreeNode *dfs(int n, ListNode *&pt){
        if (n == 0) return NULL;
        int l = (n-1)/2, r = n-1-l;
        TreeNode *lson = dfs(l, pt);
        TreeNode *node = new TreeNode(pt->val);
        pt = pt->next;
        node->left = lson;
        node->right = dfs(r, pt);
        return node;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        int n = 0;
        for (ListNode *p = head; p; p = p->next){
            n++;
        }
        return dfs(n, head);
    }
};
