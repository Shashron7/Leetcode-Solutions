class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> pre(n,0);

        pre[0]=nums[0];
        for(int i=1; i<n; i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }

        for(auto it : pre) cout<<it<<" ";

        int l=0;
        int ans=nums[0];

        for(int r=1; r<n; r++)
        {
            if(nums[r] <=nums[r-1])
            {
                int curr= l==0 ? pre[r-1] : pre[r-1]-pre[l-1];
                ans=max(ans,curr);
                l=r;
            }

        }
        ans=max(ans,l==0 ? pre[n-1] : pre[n-1]-pre[l-1]);
        return ans;
    }
};