// Source Code:

int mycount(TreeNode* root,int sum){
    if(!root)
        return 0;
        
    return (root->val == sum)  + mycount(root->left,sum-root->val) + mycount(root->right,sum-root->val);
}

int pathSum(TreeNode* root, int sum){
    if(!root)
        return 0;
        
    return mycount(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
}