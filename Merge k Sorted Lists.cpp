class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        multimap<int, int> res;
        for (unsigned i = 0; i<lists.size(); i++){
            if (lists[i]!=NULL){
                res.insert(make_pair(lists[i]->val, i));
            }
        }
        ListNode *head = NULL, *tail = NULL;
        while (res.size()){
            int x = res.begin()->second;
            res.erase(res.begin());
            if (head == NULL){
                head = tail = lists[x];
            }else{
                tail = tail->next = lists[x];
            }
            lists[x] = lists[x]->next;
            if (lists[x] != NULL){
                res.insert(make_pair(lists[x]->val, x));
            }
        }
        return head;
    }
};
