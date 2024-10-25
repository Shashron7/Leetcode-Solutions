class Solution {
public:
    bool check(int src,  vector<int> adj[], vector<int>& v)
    {
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            for(auto it: adj[temp])
            {
                if(v[it]==-1)
                {
                    v[it]=(v[temp]+1)%2;
                    q.push(it);
                }
                else if(v[it]==v[temp]) return false;
            }
        }
        return true;
    }
    bool func(vector<int> adj[], int n)
    {
        vector<int> v(n+1,-1);
        for(int i=1; i<=n; i++)
        {
            if(v[i]==-1)
            {
                if(!check(i,adj,v)) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        for(auto it: dislikes)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return func(adj,n);


    }
};