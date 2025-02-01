class Solution {
public:

    int func(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp)
    {
        
        if(amount==0) return 0; //return 0

        if(amount < 0 || ind==coins.size()) return 1e7; //not possible

        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int take=1e7, nottake=1e7;
        take=1+func(ind,coins,amount-coins[ind],dp);
        nottake=func(ind+1,coins,amount,dp);  

        return dp[ind][amount]=min(take,nottake);
         

    }
    int coinChange(vector<int>& coins, int amount) {
        //we can take any coin any number of times 

        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));

        int a=func(0,coins,amount,dp);

        return a==1e7 ? -1 : a;
        
    }
};