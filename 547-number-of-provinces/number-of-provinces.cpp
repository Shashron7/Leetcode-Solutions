class Solution {
public:

    class DS{
        public:
        vector<int> rank, parent;

        DS(int n)
        {
            rank.resize(n,0);
            parent.resize(n,0);

            for(int i=0; i<n; i++)
            {
                parent[i]=i;
                rank[i]=1;
            }
        }

        int find(int node) //find parent node
        {
            if(parent[node]==node) return node;

            return parent[node]=find(parent[node]); //path compression
        }

        void combine(int u, int v)
        {
            int parU=find(u);
            int parV=find(v);

            if(parU==parV) return;

            if(rank[parU] > rank[parV])
            {
                parent[parV]=parU;
                rank[parU]++;
            }
            else if(rank[parU] < rank[parV])
            {
                parent[parU]=parV;
                rank[parV]++;
            }
            else
            {
                parent[parU]=parV;
                rank[parV]++;
            }
        }
    };
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        DS d(n);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isConnected[i][j])
                {
                    d.combine(i,j);
                }
            }
        }
        unordered_set<int> vis;

        for(int i=0; i<n; i++)
        {
            vis.insert(d.find(i));
        }

        return vis.size();
    }
};