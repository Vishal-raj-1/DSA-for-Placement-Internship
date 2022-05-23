// Single Pass

ListNode* removeZeroSumSublists(ListNode* head) {
    unordered_map<int, ListNode*>mp;
    ListNode *dummy = new ListNode(0), *curr = dummy;
    dummy->next = head;
    int prefixSum = 0;
    while(curr){
        prefixSum += curr->val;
        if(mp.count(prefixSum)){
            curr = mp[prefixSum]->next;
            int p = prefixSum + curr->val;
            while(p != prefixSum){
                mp.erase(p);
                curr = curr->next;
                p += curr->val;
            }
            mp[prefixSum]->next = curr->next;
        }
        else    
            mp[prefixSum] = curr;
        
        curr = curr->next;
    }
    return dummy->next;
}

// Two Passes, but clean solution

ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    int prefix = 0;
    unordered_map<int, ListNode*> seen;
    for (ListNode* i = dummy; i; i = i->next) {
        seen[prefix += i->val] = i;
    }
    prefix = 0;
    for (ListNode* i = dummy; i; i = i->next) {
        i->next = seen[prefix += i->val]->next;
    }
    return dummy->next;
}