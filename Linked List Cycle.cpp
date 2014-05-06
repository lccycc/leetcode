class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto p = head;
        while (p){
            if (p->next == NULL || p->next->next == NULL) return false;
            p = p->next->next;
            head = head->next;
            if (head == p) return true;
        }
        return false;
    }
};
