class Solution {
public:
    int func(int ind, int maxL, vector<int>& days, vector<int>& costs, vector<vector<int>>& dp)
    {
        if(ind>=days.size() || maxL > 365) return 0;

        if(dp[ind][maxL]!=-1) return dp[ind][maxL];
        int ans=0;
        int one=0, two=0, three=0;
        if(days[ind] <=maxL) ans=func(ind+1,maxL,days,costs,dp);
        else
        {
            int one=costs[0]+func(ind+1,days[ind],days,costs,dp);
            int two=costs[1]+func(ind+1,days[ind]+6,days,costs,dp);
            int three=costs[2]+func(ind+1,days[ind]+29,days,costs,dp);

            one=min(one,two);
            one=min(one,three);
            ans=one;
        }
        return dp[ind][maxL]=ans;
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        
        vector<vector<int>> dp(366, vector<int>(366,-1));
        return func(0,0,days,costs,dp);

        
    }
};