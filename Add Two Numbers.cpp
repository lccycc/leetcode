class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL, *p = head;
        int t = 0;
        while (l1 || l2 || t){
            int x = (l1?l1->val:0) + (l2?l2->val:0) + t;
            if (p){
                p = p->next = new ListNode(x%10);
            }else{
                head = p = new ListNode(x%10);
            }
            t = x/10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head;
    }
};
