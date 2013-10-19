
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k == 0) return head;
        ListNode newhead(0), *p = &newhead;
        newhead.next = head;
        int i = 0;
        while (i<k){
            p = p->next;
            i++;
            if (p->next == NULL) break;
        }
        if (p->next == NULL){
            return rotateRight(head, k%i);
        }
        ListNode *q = &newhead;
        while (p->next != NULL){
            p = p->next;
            q = q->next;
        }
        p->next = head;
        head = q->next;
        q->next = NULL;
        return head;
    }
};

