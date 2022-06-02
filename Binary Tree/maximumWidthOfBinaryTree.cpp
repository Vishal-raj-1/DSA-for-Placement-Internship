// Using Deque:

int widthOfBinaryTree(TreeNode* root){
    if(!root)
        return 0;
    
    deque<TreeNode*>dq;
    dq.push_back(root);
    
    int Max = 1;
    
    while(!dq.empty()){
        while(!dq.empty() && !dq.front())
            dq.pop_front();
        
        while(!dq.empty() && !dq.back())
            dq.pop_back();
        
        int size = dq.size();
        Max = max(Max,size);
        
        while(size--){
            TreeNode* temp = dq.front();
            dq.pop_front();
        
            if(!temp){
                dq.push_back(NULL);
                dq.push_back(NULL);
            }
            else{
                dq.push_back(temp->left);
                dq.push_back(temp->right);
            }
        }
        
    }
    return Max;
}

// Using Indexing:

int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int ans = 1;
        while(!q.empty()){
            int size = q.size();
            int start = q.front().second;
            int end = q.back().second;
            ans = max(ans, end-start+1);
            while(size--){
                auto curr = q.front();
                q.pop();
                long long index = curr.second - start;
                if(curr.first->left){
                    q.push({curr.first->left, 2*index + 1});
                }
                if(curr.first->right){
                    q.push({curr.first->right, 2*index + 2});
                }
            }
        }
        return ans;
    }