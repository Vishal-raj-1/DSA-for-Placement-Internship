// Recursive

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q)
        return true;
    
    if(!p || !q)
        return false;
    
    return p->val == q->val && isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
}
bool isSymmetric(TreeNode* root) {
    return isSameTree(root->left, root->right);
}

// Iterative Solution

bool isSymmetric(TreeNode* root) {
    if (!root) 
        return true;
    stack<TreeNode*>st;
    st.push(root->left);
    st.push(root->right);
    while (!st.empty()) {
        TreeNode *n1 = st.top(); 
        st.pop();
        TreeNode *n2 = st.top();
        st.pop();
        if (!n1 && !n2) 
            continue;
        if (!n1 || !n2 || n1->val != n2->val) 
            return false;

        st.push(n1->left);
        st.push(n2->right);
        st.push(n1->right);
        st.push(n2->left);
    }
    return true;
}
