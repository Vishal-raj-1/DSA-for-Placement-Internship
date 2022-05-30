// Top Down Appraoch:

void _depth(TreeNode *root, int depth, int &ans){
    if(!root)
        return;
    if(!root->left && !root->right)
        ans = max(ans, depth);
    
    _depth(root->left, depth+1, ans);
    _depth(root->right, depth+1, ans);
}
int maxDepth(TreeNode* root) {
    int ans = 0;
    _depth(root, 1, ans);
    return ans;
}

// Bottom Up Approach

int maxDepth(TreeNode* root) {
    if(!root)
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}