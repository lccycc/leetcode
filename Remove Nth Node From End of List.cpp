class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        /* p point to n+1 node from the end
           if there are only n node, return head->next;
           otherwise, q -> n+1 node from head, p -> head;
           move p and q forward until q reach the end of the list
           and remove the next node of p
         */
        ListNode *p, *q;
        p = head;
        for (int i = 0; i<n; i++){
            p = p->next;
            if (!p) break;
        } 
        if (!p) return head->next;
        q = head;
        while (p->next){
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        return head;
    }
};
