class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_set<int> vis;
        int z=0;
        for(auto it : arr)
        {
            vis.insert(it);
            if(!it) z++;
        }
        if(z>1) return true;

        for(auto it: arr)
        {
            if(it!=0 && vis.find(it*2)!=vis.end()) return true;
        }
        return false;
    }
};