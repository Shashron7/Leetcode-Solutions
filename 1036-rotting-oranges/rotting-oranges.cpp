class Solution {
public:
    vector<int> a={1,0,-1,0};
    vector<int> b={0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        //outline: 
        //BFS
        //all the positions that have rotten oranges
        //queue and we'll push all the rotten oranges there-- iterate through the matrix and get all the rotten oranges
        //visited array which will help us keep track visited cells

        //BFS from all the rotten oranges
        //{time,{i,j}} 
        // we'll iterate through the matrix and see if there's any rotten oranges left or not-- if yes return -1 else return the mins


        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));


        queue<pair<int,pair<int,int>>> q;  //{time,{i,j}} 
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}}); //push all rotten oranges here
                    vis[i][j]=1;
                }
            }
        }
        int tm=0; // maxtime
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            int t=temp.first;
            int i=temp.second.first;
            int j=temp.second.second;

            tm=max(t,tm);
            for(int x=0; x<4; x++)
            {
                int newi=i+a[x];
                int newj=j+b[x];

                if(newi>=0 && newj>=0 && newi<grid.size() && newj<grid[0].size() && !vis[newi][newj] && grid[newi][newj]==1)
                {
                    q.push({t+1,{newi,newj}});
                    vis[newi][newj]=1;

                    
                }
            }



        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
               if(vis[i][j]==0 && grid[i][j]==1) return -1;

            }
            
        }

        return tm;
        
    }
};