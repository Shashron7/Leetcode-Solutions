class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> rows(n,0);
        vector<int> cols(m,0);
        for(int i=0; i<n; i++)
        {
            int val=count(grid[i].begin(), grid[i].end(),1);
            rows[i]=val;
        }

        for(int j=0; j<m; j++)
        {
            int val=0;
            for(int i=0; i<n;i++)
            {
                if(grid[i][j]) val++;
            }
            cols[j]=val;
        }

        for(auto it: cols) cout<<it<<" ";
        cout<<endl;
        for(auto it: rows) cout<<it<<" ";

        int ans=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j])
                {
                    if(rows[i] > 1 ||  cols[j] > 1) ans++;
                }
            }
        }
        return ans;
    }
};