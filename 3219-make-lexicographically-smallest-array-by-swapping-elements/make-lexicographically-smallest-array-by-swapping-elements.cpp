class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> item;
        int n = nums.size();
        for(int i=0; i<n; i++) item.push_back({nums[i],i});
        sort(item.begin(), item.end());

        int start=0;
        set<int> indices={item[0].second};
        vector<int> res(n);
        for(int i=1; i<n; i++){
            if(item[i].first - item[i-1].first > limit){
                for(const int &idx:indices) res[idx]=item[start++].first;
                indices.clear();
            }
            indices.insert(item[i].second);
        }
        for(const int &idx:indices) res[idx]=item[start++].first;
        return res;
    }
};