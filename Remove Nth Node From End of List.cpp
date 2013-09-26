class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *newhead = new ListNode(0), *p = newhead, *q = p;
        newhead->next = head;
        for (int i = 0; i<n; i++){
            p = p->next;
        }
        while (p->next != NULL){
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        head = newhead->next;
        free(newhead);
        return head;
    }
};
