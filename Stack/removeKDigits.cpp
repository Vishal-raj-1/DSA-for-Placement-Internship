// Source Code:

string removeKdigits(string num, int k){
    string ans = ""; // treat ans as a stack in below for loop
    for (char c : num){
        while (ans.length() && ans.back() > c && k){
            ans.pop_back(); // make sure digits in ans are in ascending order
            k--;            // remove one char
        }
        if (ans.length() || c != '0'){
            ans.push_back(c);
        } // can't have leading '0'
    }

    // make sure remove k digits in total
    while (ans.length() && k--)
        ans.pop_back();

    return ans.empty() ? "0" : ans;
}