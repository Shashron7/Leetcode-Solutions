class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
       
        priority_queue< pair<int,int>,vector< pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i=0; i<nums.size(); i++)
        {
            pq.push({nums[i], i});
        }
        vector<int> ans(nums.size(),0);
        while(k-- && !pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            pq.push({temp.first*m, temp.second});
        }

        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            ans[temp.second]=temp.first;
        }
        return ans;
    }
};