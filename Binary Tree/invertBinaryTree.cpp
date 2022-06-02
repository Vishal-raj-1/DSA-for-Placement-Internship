// Iterative Approach:

TreeNode* invertTree(TreeNode* root) {
    stack<TreeNode*>s;
    s.push(root);
    while(!s.empty()){
        TreeNode* curr = s.top();
        s.pop();
        if(curr){
            s.push(curr->left);
            s.push(curr->right);
            swap(curr->left, curr->right);
        }
    }
    return root;
}

// Recursive Approach:

TreeNode* invertTree(TreeNode* root) {
    if(!root)
        return NULL;
    
    swap(root->right, root->left);
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}