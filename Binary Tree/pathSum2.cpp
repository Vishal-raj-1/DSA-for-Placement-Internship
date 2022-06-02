// Source Code:

void allPathSum(TreeNode* root, int targetSum, vector<int>v, vector<vector<int>>& ans){
    if(!root)
        return;
    targetSum -= root->val;
    v.push_back(root->val);
    if(!root->left && !root->right){
        if(targetSum == 0)
            ans.push_back(v);
        
        return;
    }
    
    allPathSum(root->left, targetSum, v, ans);
    allPathSum(root->right, targetSum, v, ans);
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int>v;
    vector<vector<int>> ans;
    allPathSum(root, targetSum, v, ans);
    return ans;
}