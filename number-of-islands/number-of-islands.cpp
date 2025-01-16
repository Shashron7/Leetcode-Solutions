class Solution {
public:
    vector<int> a={1,0,-1,0};
    vector<int> b={0,1,0,-1};
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis)
    {
        
        vis[i][j]=1;

        for(int x=0; x<4; x++)
        {
            int newi=i+a[x];
            int newj=j+b[x];

            if(newi>=0 && newj>=0 && newi<grid.size() && newj<grid[0].size() && grid[newi][newj]=='1' && !vis[newi][newj])
            {
                dfs(newi,newj,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }

        return count ;

        

        
    }
};