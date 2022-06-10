// 2-pointer approach( two sumii solution)

vector<int> twoSum(vector<int>& numbers, int target) {
    int i=0, j = numbers.size()-1;
    while(i < j){
        if(numbers[i] + numbers[j] == target)
            break;
        else if(numbers[i] + numbers[j] > target)
            j--;
        else
            i++;
    }
    return {i+1,j+1}; // 1-indexed 
}

// Using HashMap (two sum solution)

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>result;
    unordered_map<int,int>mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target-nums[i]) != mp.end())
        {
            result.push_back(i);
            result.push_back(mp[target-nums[i]]);
            break;
        }
        else
            mp[nums[i]] = i;
    }
    return result;
}