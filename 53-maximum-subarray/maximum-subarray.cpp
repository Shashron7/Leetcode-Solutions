class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum=0;
        int maxsum=-1e9;

        for(int i=0; i<nums.size(); i++)
        {
            if(sum < 0) sum=0;

            sum+=nums[i];

            maxsum=max(maxsum,sum);
            
        }

        return maxsum;
    }
};