// BFS Approach:

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root)
        return ans;
    int level = 0;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>v;
        int size = q.size();
        while(size--){
            TreeNode* curr = q.front();
            q.pop();
            v.push_back(curr->val);
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        if(level & 1)
            reverse(v.begin(), v.end());
        ans.push_back(v);
        level++;
    }
    return ans;
}