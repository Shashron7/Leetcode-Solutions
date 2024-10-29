class Solution {
public:
    vector<int> a={-1,0,1};
    int func(int i, int j, vector<vector<int>>& grid, int pi, int pj, int n, int m, vector<vector<int>>& dp)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(int x=0; x<3; x++)
        {
            if(i+a[x] < n && j+1<m && i+a[x]>=0 && j+1>=0 && grid[i+a[x]][j+1] > grid[i][j])
            {
                int curr=1+func(i+a[x],j+1,grid,i,j,n,m,dp);
                ans=max(ans,curr);
            }
        }   
        return dp[i][j]=ans;

    }
    int maxMoves(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        int ans=0;
        for(int i=0; i<n;i++)
        {
            ans=max(ans,func(i,0,grid,-1,-1,n,m,dp));
        }
        return ans;
        
    }
};