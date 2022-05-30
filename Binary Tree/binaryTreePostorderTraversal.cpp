// Recursive Solution

void postOrder(TreeNode* root, vector<int>& ans){
    if(root == NULL)
        return ;
    postOrder(root->left, ans);        
    postOrder(root->right, ans);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int>ans;
    postOrder(root, ans);
    return ans;
}

// Iterative Solution

vector<int> postorderTraversal(TreeNode* root) {
    if(!root)
        return {};
    vector<int>ans;
    stack<TreeNode*>st;
    TreeNode *curr = root, *last = NULL;
    while(curr || !st.empty()){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }
        else{
            TreeNode *node = st.top();
            if(node->right && node->right != last)
                curr = node->right;
            else{
                st.pop();
                ans.push_back(node->val);
                last = node;
            }
        }
    }
    return ans;
}