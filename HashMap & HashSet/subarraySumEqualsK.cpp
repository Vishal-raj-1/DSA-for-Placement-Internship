// Source Code:

int subarraySum(vector<int>& nums, int k){
    unordered_map<int,int>m;
    int ans = 0,sum = 0;
    
    m[0] = 1;
    for(int i=0,n = nums.size(); i<n; i++){
        sum += nums[i];
        
        if(m.find(sum - k) != m.end())
            ans += m[sum - k];
        
        m[sum]++;
    }
    
    return ans;
}