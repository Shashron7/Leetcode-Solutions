class Solution {
public:
    vector<int> a={1,0,-1,0};
    vector<int> b={0,1,0,-1};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        
        vector<vector<int>> dist(n ,vector<int>(m,0));
        vector<vector<int>> vis(n ,vector<int>(m,0));


        queue<pair<int,pair<int,int>>> q;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(isWater[i][j]==1) //processing all the water cells
                {
                    dist[i][j]=0;
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }


        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();

            int h=temp.first;
            int i=temp.second.first;
            int j=temp.second.second;

            for(int x=0; x<4; x++)
            {
                int newi=i+a[x];
                int newj=j+b[x];

                if(newi >=0 && newj>=0 && newi<n && newj<m && !vis[newi][newj])
                {
                    q.push({h+1,{newi,newj}});
                    vis[newi][newj]=1;
                    dist[newi][newj]=h+1;
                }
            }
        }



        return dist;
    }
};