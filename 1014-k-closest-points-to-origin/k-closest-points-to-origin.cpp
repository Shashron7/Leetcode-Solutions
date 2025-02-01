class Solution {
public:
    int dist(int i, int j)
    {
        return i*i+j*j;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; //min heap

        for(auto it: points)
        {
            int currd=dist(it[0],it[1]);
            pq.push({currd,{it[0],it[1]}});
        }

        vector<vector<int>> ans;
        while(k--)
        {
            auto temp=pq.top();
            pq.pop();
            ans.push_back({temp.second.first, temp.second.second});
        }

        return ans;
    }
};