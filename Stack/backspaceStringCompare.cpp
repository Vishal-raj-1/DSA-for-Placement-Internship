// Solution (using Stack)

bool backspaceCompare(string s, string t) {
    stack<char>s1, s2;
    for(int i=0; i<s.size(); i++){
        if(s[i] != '#')
            s1.push(s[i]);
        else if(!s1.empty())
            s1.pop();
    }
    
    for(int i=0; i<t.size(); i++){
        if(t[i] != '#')
            s2.push(t[i]);
        else if(!s2.empty())
            s2.pop();
    }
    
    if(s1.size() != s2.size())
        return false;
    
    while(!s1.empty()){
        if(s1.top() != s2.top())
            return false;
        s1.pop();
        s2.pop();
    }
    return true;
}

// Optimal Approach

bool backspaceCompare(string s, string t){
    int i = s.size() - 1, j = t.size() - 1, skipS = 0, skipT = 0;
    while(i >= 0|| j >= 0){
        while(i >= 0){
            if(s[i] == '#')
                i--, skipS++;
            else if(skipS > 0)
                i--, skipS--;
            else
                break;
        }

        while(j >= 0){
            if(t[j] == '#')
                j--, skipT++;
            else if(skipT > 0)
                j--, skipT--;
            else
                break;
        }

        if(i >= 0 && j >= 0 && s[i] != t[j])
            return false;

        if((i >= 0) != (j >= 0))
            return false;
        
        i--, j--;
    }
    return true;
}