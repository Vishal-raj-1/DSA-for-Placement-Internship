// Intuitive Solution

class Solution {
public:
    ListNode* getMid(ListNode* head)
    {
        ListNode *slow = head,*fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* getReverse(ListNode* head)
    {
        ListNode *cur = head,*prev = NULL;
        while(cur)
        {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        
        if(head==NULL||head->next==NULL||head->next->next==NULL)
            return;
        ListNode* mid = getMid(head);
        ListNode* secondHalf = mid->next;
        mid->next=NULL;
        ListNode* revHalf = getReverse(secondHalf);
        while(head && revHalf)
        {
            ListNode* temp = head->next;
            head->next=revHalf;
            revHalf=revHalf->next;
            head->next->next=temp;
            head = temp;
        }
    }
};