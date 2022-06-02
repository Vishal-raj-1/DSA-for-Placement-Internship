// Source Code:

class Solution {
public:
    bool isPath(ListNode* head, TreeNode* root){
        if(!head)
            return true;
        
        if(!root)
            return false;
        
        return (root->val == head->val) && (isPath(head->next, root->left) || isPath(head->next, root->right));
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root)
            return false;
        
        return (root->val == head->val && isPath(head, root)) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};