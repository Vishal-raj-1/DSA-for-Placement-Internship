// Source Code:

class Solution {
public:
    TreeNode* build(vector<int>& preorder, int pStart, int pEnd, unordered_map<int, int>& inorderMap, int iStart, int iEnd){
        if(pStart > pEnd || iStart > iEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[pStart]);
        int iRoot = inorderMap[root->val];
        int numsLeft = iRoot - iStart;
        
        root->left = build(preorder, pStart + 1, pStart + numsLeft, inorderMap, iStart, iRoot - 1);        
        root->right = build(preorder, pStart + 1 + numsLeft, pEnd, inorderMap, iRoot + 1, iEnd);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>inorderMap;
        for(int i=0; i<inorder.size(); i++)
            inorderMap[inorder[i]] = i;
        
        return build(preorder, 0, preorder.size() - 1, inorderMap, 0, inorder.size() - 1);
    }
};