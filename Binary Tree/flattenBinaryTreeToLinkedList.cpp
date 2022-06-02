// Using Stack

void flatten(TreeNode* root) {
    if(!root)
        return;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        if(curr->right)
            st.push(curr->right);
        if(curr->left)
            st.push(curr->left);
        if(!st.empty())
            curr->right = st.top();
        curr->left = NULL;
    }
}

// Recursive:

class Solution
{
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root)
    {
        if(!root)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

// Morris Traversal:

void flatten(TreeNode* root){
    if(!root)
        return;

    TreeNode *curr = root;
    TreeNode *last = NULL;

    while(curr){
        if(curr->left){
            last = curr->left;

            while(last->right)
                last = last->right;

            last->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}