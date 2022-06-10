// Source Code:

class Solution {
public:
    int solve(TreeNode* root, unordered_map<int,int> &mp){
        if(!root)
            return 0;
        int leftSum = solve(root->left,mp);        
        int rightSum = solve(root->right, mp);
        int rootSum = leftSum + rightSum + root->val;
        mp[rootSum]++;
        return rootSum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>mp;
        solve(root, mp);
        priority_queue<pair<int,int> >pq;
        for(auto itr: mp)
            pq.push({itr.second, itr.first});
        
        vector<int>ans;
        int freq = pq.top().first;
        while(!pq.empty() && freq == pq.top().first){
            auto c = pq.top();
            pq.pop();
            ans.push_back(c.second);
        }
        return ans;
    }
};