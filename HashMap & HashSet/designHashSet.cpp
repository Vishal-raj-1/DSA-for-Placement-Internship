// Using Array

class MyHashSet
{
    int arr[1000000];
public:
    MyHashSet()
    {
        memset(arr,-1,sizeof(arr));
    }

    void add(int key)
    {
        arr[key] = 0;
    }

    void remove(int key)
    {
        arr[key] = -1;
    }

    bool contains(int key)
    {
         return arr[key] == 0;
    }
};

// Using Bucket List:

class MyHashSet {
public:
    int bucketSize = 123;
    vector<int>bucket[123];
    MyHashSet() {
        
    }
    
    void add(int key) {
        int index = key % bucketSize;
        if(!contains(key))
            bucket[index].push_back(key);
    }
    
    void remove(int key) {
        int index = key % bucketSize;
        for(int i = 0; i < bucket[index].size(); i++){
            if(bucket[index][i] == key){
                bucket[index].erase(bucket[index].begin() + i); 
                break;
            }
        }
    }
    
    bool contains(int key) {
        int index = key % bucketSize;
        for(auto itr : bucket[index]){
            if(itr == key)
                return true;
        }
        return false;
    }
};