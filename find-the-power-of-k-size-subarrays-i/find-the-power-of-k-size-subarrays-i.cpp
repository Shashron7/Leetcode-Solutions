class Solution {
public:
    // bool check(vector<int>& nums)
    // {
    //     for(int i=1; i<nums.size(); i++)
    //     {
    //         if(nums[i]-nums[i-1]!=1) return false;
    //     }
    //     return true;
    // }
    vector<int> resultsArray(vector<int>& nums, int k)
    {
       int len=0;
       int l=0;
       vector<int> ans;
       for(int r=0; r<nums.size(); r++)
       {
            if(r==0 || (r>0 && nums[r]-nums[r-1]==1)) len++;
            if(r>0 && nums[r]-nums[r-1]!=1) len=1;
            cout<<"r is "<<r<<" len  is "<<len<<endl;
            while(len > k)
            {
                len--;
            }
            if(r>=k-1)
            {
                if(len==k) ans.push_back(nums[r]);
                else ans.push_back(-1);
            }

            


       }
       return ans;
    }
       
};