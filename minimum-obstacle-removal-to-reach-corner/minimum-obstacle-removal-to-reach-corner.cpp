class Solution {
public:
    vector<int> a={-1,0,1,0};
    vector<int> b={0,1,0,-1};
    
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        pq.push({0,{0,0}}); //starting at 0,0
        dist[0][0]=0;

        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            pair<int,int> curr=temp.second;
            int obs=temp.first;
            int i=curr.first;
            int j=curr.second;
            if(i==n-1 && j==m-1) return obs;
            for(int x=0; x<4; x++)
            {
                int newi=i+a[x];
                int newj=j+b[x];
                if(newi>=0 && newj>=0 && newi<n && newj<m)
                {
                    if(grid[newi][newj])
                    {
                        if(dist[newi][newj] > 1+ dist[i][j])
                        {
                            dist[newi][newj]=1+dist[i][j];
                            pq.push({1+dist[i][j],{newi,newj}});
                        }
                    }
                    else
                    {
                        if(dist[newi][newj] > dist[i][j])
                        {
                            dist[newi][newj]=dist[i][j];
                            pq.push({dist[i][j],{newi,newj}});
                        }
                    }
                }
            }
        }
        return -1;

    }
};