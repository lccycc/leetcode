/*
    consider the sub index of p as x when p meets q. head has subindex of 0
    assume the length of loop ls L
    then, q has a sub index of 2x, we got that L | 2x-x  -> L | x
    so p differs with head for several whole loop. they will meet.
    and the meet point must be the start of loop
*/
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
