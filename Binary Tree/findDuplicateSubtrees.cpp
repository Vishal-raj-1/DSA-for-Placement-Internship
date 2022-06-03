// Source Code:

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>m;
        vector<TreeNode*>ans;
        
        if(!root)
            return ans;
            
        string tree = serialize(root,m,ans);
        return ans;
    }
    
    string serialize(TreeNode* root,unordered_map<string,int>&m,vector<TreeNode*>&ans){
        if(!root)
            return "";
            
        string sub = to_string(root->val) + ',' + serialize(root->left,m,ans) + ',' + serialize(root->right,m,ans);

        if(++m[sub] == 2)
            ans.push_back(root);
            
        return sub;
    }
};