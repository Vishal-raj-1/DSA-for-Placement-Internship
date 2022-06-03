// Brute Force Approach:

int countNodes(TreeNode* root) {
    if(!root)
        return 0;
    
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    
    return left+ right +1;
}

// Optimal Approach:

class Solution {
public:
    int height(TreeNode* root){
        return root ? 1 + height(root->left) : 0;
    }
    int countNodes(TreeNode* root) {
        int h = height(root);
        if(h == 0)
            return 0;
        else if(height(root->right) == h-1)
            return (1 << h-1) + countNodes(root->right);
        else
            return (1 << h-2) + countNodes(root->left);
    }
};