class NumberContainers {
public:

    // hashmap index -> number

    // hashmap storing the minm index for that 
    // map<int,set<int>> mp; number to indices

    //minm index will be the first element of the set
    

    // 
    map<int,int> mp1;
    map<int,set<int>> mp2;


    NumberContainers() {
        
        mp1.clear();
        mp2.clear();

    }
    
    void change(int index, int number) {
        
        if(mp1.find(index)!=mp1.end())
        {
            int n=mp1[index];
            
            mp2[n].erase(index);
            if(mp2[n].empty()) mp2.erase(n);
        }

        
        mp1[index]=number;
        mp2[number].insert(index);
    }
    
    int find(int number) {
        
        if(mp2.find(number)==mp2.end()) return -1;
        return *mp2[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */