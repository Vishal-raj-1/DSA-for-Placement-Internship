// Brute Force Approach

class StockSpanner {
public:
    vector<int>v;
    StockSpanner() {
    }
    
    int next(int price) {
        v.push_back(price);
        int ans = 1;
        for(int i=v.size()-1; i> 0; i--){
            if(price >= v[i-1])
                ans++;
            else
                break;
        }
        return ans;
    }
};

// Optimal Solution: Using Stack

class StockSpanner
{
public:
    stack<pair<int,int>>s;
    StockSpanner(){
    }

    int next(int price)
    {
        int ans = 1;
        while(!s.empty() && s.top().first <= price ){
            ans += s.top().second;
            s.pop();
        }
        s.push({price, ans});
        return ans;
    }
};