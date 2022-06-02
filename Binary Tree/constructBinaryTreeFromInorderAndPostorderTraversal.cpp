// Source Code:

class Solution {
public:
    TreeNode* build(unordered_map<int, int>& inorderMap, int iStart,int iEnd, vector<int>& postorder, int pStart, int pEnd){
        if(pStart > pEnd || iStart > iEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[pEnd]);
        int iRoot = inorderMap[root->val];
        int numsRight = iEnd - iRoot;
        
        root->left = build(inorderMap, iStart, iRoot - 1, postorder, pStart,pEnd - numsRight - 1);       
        root->right = build(inorderMap, iRoot + 1, iEnd, postorder, pEnd - numsRight, pEnd - 1 );
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int>inorderMap;
        for(int i=0; i<inorder.size(); i++)
            inorderMap[inorder[i]] = i;
        
        return build(inorderMap, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};