// Optimal Solution

int sumSubarrayMins(vector<int> &arr){
    long n = arr.size();
    vector<int>left(n), right(n);
    stack<pair<int,int>>s1,s2;
    for (int i = 0; i < n; i++){
        int count = 1;
        while(!s1.empty() && s1.top().first > arr[i]){
            count += s1.top().second;
            s1.pop();
        }
        s1.push({arr[i], count});
        left[i] = count;
    }
    for (int i = n-1; i >= 0; i--){
        int count = 1;
        while(!s2.empty() && s2.top().first >= arr[i]){
            count += s2.top().second;
            s2.pop();
        }
        s2.push({arr[i], count});
        right[i] = count;
    }

    long res = 0, mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
        res = (res + (long)arr[i]*left[i]*right[i])%mod;

    return res;
}