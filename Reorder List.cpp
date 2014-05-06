class Solution {
public:
    void reorderList(ListNode *head) {
        int n = 0;
        for (auto p = head; p; p = p->next){
            n++;
        }
        if (n<=2) return ;
        auto r = head;
        for (int i = 0; i<(n-1)/2; i++){
            r = r->next;
        }
        auto h = r->next; r->next = NULL;
        ListNode *p = NULL;
        while (h){
            auto tmp = h->next;
            h->next = p;
            p = h;
            h = tmp;
        }
        for (r = head; p; r = r->next){
            auto tmp = p->next;
            p->next = r->next;
            r->next = p;
            r = p;
            p = tmp;
        }
    }
};
