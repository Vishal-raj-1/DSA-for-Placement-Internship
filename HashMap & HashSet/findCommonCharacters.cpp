// Source Code:

vector<string> commonChars(vector<string>& A){
    vector<int> common(26,INT_MAX);
    vector<string> res;

    for (auto s : A){
        vector<int> cnt(26, 0);
        for (auto c : s)
            cnt[c - 'a']++;
        for (auto i = 0; i < 26; i++)
            common[i] = min(common[i], cnt[i]);
    }

    for (auto i = 0; i < 26; i++)
        for (auto j = 0; j < common[i]; j++)
            res.push_back(string(1, i + 'a'));
        
    return res;
}