// Source Code:

class Solution 
{
public:
    void getMaxDiff(TreeNode* root,int Max,int Min,int &diff)
    {
        if(!root)
            return;
            
        Max = max(Max,root->val);
        Min = min(Min,root->val);
        
        diff = max(Max-Min,diff);
        
        getMaxDiff(root->left,Max,Min,diff);
        getMaxDiff(root->right,Max,Min,diff);
    }
    
    int maxAncestorDiff(TreeNode* root) 
    {
        int Max = INT_MIN,Min = INT_MAX,diff = INT_MIN;
        
        getMaxDiff(root,Max,Min,diff);
        
        return diff;
    }
};