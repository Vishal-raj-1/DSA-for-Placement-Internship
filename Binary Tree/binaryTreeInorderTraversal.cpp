// Recursive Solution

void inOrder(TreeNode* root, vector<int>& ans){
    if(root == NULL)
        return;
    inOrder(root->left, ans);    
    ans.push_back(root->val);
    inOrder(root->right, ans);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int>ans;
    inOrder(root, ans);
    return ans;
}

// Iterative Solution

vector<int> inorderTraversal(TreeNode* root) {
    vector<int>ans;
    stack<TreeNode*>st;
    TreeNode* curr = root;
    while(curr || !st.empty()){
        while(curr){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        curr = curr->right;
    }
    return ans;
}