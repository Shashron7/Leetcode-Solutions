class Solution {
public:
    vector<int> check(vector<vector<int>>& v, int n)
    {
        int l=0;
        int r=v.size()-1;
        

        while(l<=r)
        {
            int mid=(l+r)>>1;

            if(n<=v[mid][1] && n>=v[mid][0]) return v[mid];
            else if(n < v[mid][0]) r=mid-1;
            else if( n > v[mid][1]) l=mid+1;
        }
        return {};
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> v;

        int start=0;
        for(int r=0; r<nums.size(); r++)
        {
            if(r<nums.size()-1)
            {
                int curr=nums[r]+nums[r+1];
                if(curr%2==0)
                {
                    v.push_back({start,r});
                    start=r+1;
                }

            }
            else
            {
                v.push_back({start,r});
            }
        }

        vector<bool> ans;
        for(auto it: queries)
        {
            vector<int> one=check(v,it[0]);
            vector<int> two=check(v,it[1]);

            ans.push_back(one==two);
            
        }
        return ans;
    }
};