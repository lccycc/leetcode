class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL){
            return NULL;
        }
        if (head->next == NULL){
            return new TreeNode(head->val);
        }
        int num = 0;
        ListNode *p = head;
        while (p!=NULL){
            num++;
            p = p->next;
        }
        num/=2;
        p = head;
        while (--num){
            p = p->next;
        }
        TreeNode *t = new TreeNode(p->next->val);
        ListNode *q = p->next->next;
        p->next = NULL;
        t->left = sortedListToBST(head);
        t->right = sortedListToBST(q);
        return t;
    }
};
