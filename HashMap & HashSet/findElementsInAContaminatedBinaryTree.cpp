// Source Code:

class FindElements {
public:
    unordered_set<int>BT;
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    void dfs(TreeNode* root, int val){
        if(!root)
            return;
        root->val = val;
        BT.insert(val);
        dfs(root->left, 2*val + 1);        
        dfs(root->right, 2*val + 2);
    }
    
    bool find(int target) {
        return (BT.find(target) != BT.end());
    }
};