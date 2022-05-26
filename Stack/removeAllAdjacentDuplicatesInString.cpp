// Source Code:

string removeDuplicates(string s) {
    stack<char>st;
    st.push(s[0]);
    for(int i=1; i<s.size(); i++){
        if(!st.empty() && s[i] == st.top())
            st.pop();
        else
            st.push(s[i]);   
    }
    string s1 = "";
    while(!st.empty()){
        s1 += st.top();
        st.pop();
    }
    reverse(s1.begin(), s1.end());
    return s1;
}