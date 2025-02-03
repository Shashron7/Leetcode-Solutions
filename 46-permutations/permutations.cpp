class Solution {
public:

    void func(int size,vector<int>& nums, vector<int>& v, vector<vector<int>>& ans,vector<int>& vis)
    {
        if(size==nums.size())
        {
            ans.push_back(v);
            return ;
        }

        for(int i=0; i<nums.size(); i++)
        {
            if(!vis[i])
            {
                v.push_back(nums[i]);
                vis[i]=1;
                func(size+1,nums,v,ans,vis);
                vis[i]=0;
                v.pop_back();
            }
        }


    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> vis(nums.size(),0); //track visited

        vector<int> v;
        vector<vector<int>> ans;

        func(0,nums,v,ans,vis);
        return ans;
    }
};