class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        multiset<int> ms;

        int l=0;
        for(int r=0; r<nums.size(); r++)
        {
            ms.insert(nums[r]);
            while(*ms.rbegin()-*ms.begin() > 2)
            {
                auto it=ms.find(nums[l]);
                ms.erase(it);
                l++;
            }
            ans +=(r-l+1);
            
        }
        return ans;
    


    }
};