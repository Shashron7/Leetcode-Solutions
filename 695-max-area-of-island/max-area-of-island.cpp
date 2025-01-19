class Solution {
public:
    vector<int> a={1,0,-1,0};
    vector<int> b={0,-1,0,1};

    int dfs(int i, int j,vector<vector<int>>& grid, vector<vector<int>>& vis)
    {
        if(grid[i][j]==0) return 0;

        vis[i][j]=1; //visited

        int ans=1; //ans
        for(int x=0; x<4; x++)
        {
            int newi=i+a[x];
            int newj=j+b[x];

            if(newi>=0 && newj>=0 && newi<grid.size() && newj<grid[0].size() && !vis[newi][newj])
            {
                ans+=dfs(newi,newj,grid,vis);
            }
        }
        cout<<"ans is "<<ans<<endl;
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //DFS
        //integer value
        //if the current cell is 0 return 0
        //if 1 then just traverse to the adjacent cells
        //visited array 


        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0)); //vis array

        int ans=0; //max value to be stored in this ans var
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && grid[i][j]) ans=max(ans,dfs(i,j,grid,vis));
            }
        }

        return ans;
    }
};