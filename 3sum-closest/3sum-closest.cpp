class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<nums.size(); i++)
        {
            int curr=nums[i];

            int j=i+1;
            int k=nums.size()-1;
            while(j<k)
            {
                int currsum=curr+nums[j]+nums[k];
                if(currsum< target)
                {
                    int diff=abs(target-currsum);
                    pq.push({diff,currsum});
                    j++;
                }
                else if(currsum > target)
                {
                    int diff=abs(target-currsum);
                    
                    pq.push({diff,currsum});
                    k--;
                }
                else return currsum;
            }
        }

        return pq.top().second;
    }
};