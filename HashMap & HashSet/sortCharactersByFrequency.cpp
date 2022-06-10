// Source Code:

string frequencySort(string s) {
    unordered_map<char, int>mp;
    for(int i=0; i<s.size(); i++)
        mp[s[i]]++;
    
    priority_queue<pair<int,char>>pq;
    for(auto itr : mp)
        pq.push({itr.second, itr.first});
    
    string ans = "";
    while(!pq.empty()){
        auto c = pq.top();
        pq.pop();
        while(c.first--){
            ans.push_back(c.second);
        }
    }
    return ans;
}