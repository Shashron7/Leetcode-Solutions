class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());
        vector<int> interval=intervals[0];
        int n=intervals.size();
        for(int i=1; i<n; i++)
        {
            if(interval[1] < intervals[i][0])
            {
                ans.push_back(interval);
                interval=intervals[i];
            }
            else
            {
                interval[0]=min(interval[0],intervals[i][0]);
                interval[1]=max(interval[1],intervals[i][1]);
            }
        }

        ans.push_back(interval);
        return ans;
    }
};