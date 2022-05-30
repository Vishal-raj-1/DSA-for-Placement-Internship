// Source Code:

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int> >ans;
    if(root == NULL)
        return ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>v;
        int size = q.size();
        while(size--){
            TreeNode* temp = q.front();
            q.pop();
            v.push_back(temp->val);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        ans.push_back(v);
    }
    return ans;
}