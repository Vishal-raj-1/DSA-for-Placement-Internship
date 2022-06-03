// Two Pass Solution:

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode *root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *first, *last;
        while(!q.empty()) {
            first = q.front(); last = q.back();
            int sz = q.size();
            while(sz--) {
                auto node = q.front(); q.pop();
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
        }
        return lca(root, first, last);
    }
    
    TreeNode* lca(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(!root || root == p || root == q) return root;
        auto left = lca(root -> left, p, q);
        auto right = lca(root -> right, p, q);
        return left ? right ? root : left : right;
    }
};

// Single Pass Solution:

class Solution {
public:
    pair<int, TreeNode*> deep(TreeNode* root){
        if(!root)
            return {0, NULL};
        auto l = deep(root->left), r = deep(root->right);
        int dl = l.first, dr = r.first;
        return {max(dl, dr)+ 1, dl == dr ? root : dl > dr ? l.second : r.second};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return deep(root).second;
    }
};