class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto p = head, q = head;
        if (!p) return NULL;
        int n = 0;
        while (p){
            if (p->next == NULL || p->next->next == NULL) return NULL;
            p = p->next->next;
            q = q->next;
            n++;
            if (q == p) break;
        }
        int l = 0;
        while (true){
            p = p->next;
            l++;
            if (p == q) break;
        }
        for (int i = 0; i<(l-n%l)%l; i++){
            p = p->next;
        }
        while (head != p){
            head = head->next;
            p = p->next;
        }
        return p;
    }
};
