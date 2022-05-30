// Recursive Solution

void preOrder(TreeNode* root, vector<int>& ans){
    if(root == NULL)
        return ;
    ans.push_back(root->val);
    preOrder(root->left, ans);        
    preOrder(root->right, ans);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int>ans;
    preOrder(root, ans);
    return ans;
}

// Iterative Solution

vector<int> preorderTraversal(TreeNode* root) {
    if(!root)
        return {};
    vector<int>ans;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        if(curr->right)
            st.push(curr->right);
        
        if(curr->left)
            st.push(curr->left);
    }
    return ans;
}