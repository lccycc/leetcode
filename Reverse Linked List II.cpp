/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode *reverse(ListNode *phead, ListNode *t){
    ListNode *tail = t->next, *ptail = phead->next;
    while (tail != t){
        ListNode *tmp = phead->next->next;
        phead->next->next = tail;
        tail = phead->next;
        phead->next = tmp;
    }
    phead->next = tail;
    return ptail;
}
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode newhead(0), *phead, *t;
        newhead.next = head;
        int cnt = 0;
        phead = &newhead;
        m--; n--;
        while (cnt<m){
            cnt++;
            phead = phead->next;
        }
        t = phead->next;
        while (cnt<n){
            cnt++;
            t = t->next;
        }
        reverse(phead, t);
        return newhead.next;
    }
};


