class Solution {
public:
    bool check(vector<int>& nums, int n, int mop)
    {
        int op=0;

        for(auto it: nums)
        {
            if(it > n)
            {
                int q=it/n;
                int r=it%n;

                if(r > 0) op+=q;
                else op+=q-1;
            }
        }
        return op <=mop;
    }
    int minimumSize(vector<int>& nums, int mop) {
        int maxm=*(max_element(nums.begin(), nums.end()));
        int sum=0;
        int l=1, r=maxm;
        int n=nums.size();
        int ans=INT_MAX;
        while(l<=r)
        {
            int mid=(l+r)>>1;

            if(check(nums,mid,mop))
            {
                ans=min(ans,mid);
                r=mid-1;
            }
            else l=mid+1;
            

            
        }
        return ans;


    }
};