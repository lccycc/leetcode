class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto p = head, q = head;
        if (!p) return NULL;
        while (p){
            if (p->next == NULL || p->next->next == NULL) return NULL;
            p = p->next->next;
            q = q->next;
            if (q == p) break;
        }
        while (head != p){
            head = head->next;
            p = p->next;
        }
        return p;
    }
};
