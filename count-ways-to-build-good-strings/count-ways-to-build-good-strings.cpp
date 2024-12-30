class Solution {
public: int mod=1e9+7;
    int func(int size, int o, int z, int one ,int zero , int l, int h, vector<int>& dp)
    {
        if(size > h) return 0;
        if(dp[size]!=-1) return dp[size];
        int ans=0;
        if(size >= l && size<= h) ans++;

        int take=0, nottake=0;
        take=func(size+one,o+one,z,one,zero,l,h,dp);
        nottake=func(size+zero,o,z+zero,one,zero,l,h,dp);

        return dp[size]=(ans+take+nottake)%mod;

    }
    int countGoodStrings(int low, int high, int zero, int one) {
        
        
       vector<int> dp(high+1,-1);
        return func(0,0,0,one,zero,low,high,dp);

    }
};