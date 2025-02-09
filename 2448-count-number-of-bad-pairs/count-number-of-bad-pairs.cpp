class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        //total number of pairs - good pairs

        // good pairs j-i = nums[j]-nums[i]

        //nums[j]-j=nums[i]-i
        

        //[4,1,3,3]

        //[4]
        //[4,0]
        //[1]
        //

        long long  n=nums.size();

        long long  pairs=n*(n-1)/2;   

        map<int,long long> mp; //store value and freq

        for(int i=0; i<n; i++)
        {
            long long curr=nums[i]-i;
            mp[curr]++;
        }

        long long goodPairs=0;
        for(auto it: mp)
        {
            goodPairs += it.second*(it.second-1)/2;
        }

        return pairs-goodPairs;




    }
};