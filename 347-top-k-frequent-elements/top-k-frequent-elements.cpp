class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto it: nums) mp[it]++;

        //min heap 
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int size=0;
        for(auto it: mp)
        {
            if(size < k )
            {
                pq.push({it.second, it.first});
                size++;
            }
            else
            {
                if(it.second > pq.top().first)
                {
                    pq.pop();
                    pq.push({it.second, it.first});
                }
            }
           
        }


        vector<int> ans;
        
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

        
    }
};