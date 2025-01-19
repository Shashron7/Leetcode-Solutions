class Solution {
public:
    //vectors to help me go to the neighboring cells
    vector<int> a={1,0,-1,0};
    vector<int> b={0,1,0,-1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        //outline
        //A dijkstra's alg 
        //treating each cell as a node 
        //taking the max abs diff as a weighted edge

        //distance matrix-- distance from 0,0 to the current cell

        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e7));
        
        //min heap -- smallest value on the top
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});
        dist[0][0]=0; //initialised the pq and the matrix

        while(!pq.empty())
        {
            auto temp=pq.top(); //top of the pq
            pq.pop();
            int d= temp.first;
            int i=temp.second.first;
            int j=temp.second.second;

            if(i==n-1 && j==m-1) return d;

            for(int x=0; x<4; x++) 
            {
                int newi=i+a[x];
                int newj=j+b[x];

                if(newi>=0 && newj>=0 && newi<n && newj<m) //reqd conditions for the next cell to be inside the matrix
                {
                    int newd=max(d,abs(heights[i][j]-heights[newi][newj]));

                    if(newd < dist[newi][newj])
                    {
                        dist[newi][newj]=newd; 
                        pq.push({newd,{newi,newj}});
                    }
                }
            }
            

            
        }

        return -1;


    }
};