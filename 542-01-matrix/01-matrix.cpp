class Solution {
public:
    vector<int> a={1,0,-1,0};
    vector<int> b={0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        vector<vector<int>> vis(n, vector<int>(m,0));


        queue<pair<int,pair<int,int>>> q; 

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!mat[i][j])
                {
                    q.push({0,{i,j}});
                    vis[i][j]=1; //mark visited
                }
            }
        }

        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();

            int d=temp.first;
            int i=temp.second.first;
            int j=temp.second.second;

            dist[i][j]=d;

            for(int x=0; x<4; x++)
            {
                int newi=i+a[x];
                int newj=j+b[x];

                if(newi>=0 && newj>=0 && newi<n && newj<m && !vis[newi][newj])
                {
                    q.push({d+1,{newi,newj}});
                    vis[newi][newj]=1;
                }
            }


        }

        return dist;
    }
};