// Bottom Up Approach:

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p || root == q)
        return root;
    
    TreeNode* left = lowestCommonAncestor(root->left,p,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);
    
    if(!left)
        return right;
    if(!right)
        return left;
    return root;
}