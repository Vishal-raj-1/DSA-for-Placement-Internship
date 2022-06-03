// Source Code:

class Solution
{
public:
    int Sum(TreeNode* root,int currentSum)
    {
        if(!root)
            return 0;

        currentSum = currentSum*10 + root->val;

        if(!root->left && !root->right)
            return currentSum;

        return Sum(root->left,currentSum) + Sum(root->right,currentSum);
    }

    int sumNumbers(TreeNode* root)
    {
        return Sum(root,0);
    }
};