class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n]; //adjacency list bidirectional -- undirected graph


        for(auto it: connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }



      
        map<int,unordered_set<int>> mp;

        for(auto it: connections)
        {
            mp[it[0]].insert(it[1]);
        }

        

        queue<int> q; 
        vector<int> vis(n,0);
        q.push(0); //source node is 0
        vis[0]=1;

        int ans=0;
        //since bidirectional to keep track of visited nodes
        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(auto it: adj[node])
            {
                if(!vis[it])
                {
                    if(mp[node].find(it)!=mp[node].end()) ans++;
                    q.push(it);
                    vis[it]=1;
                }
            }
        }

        return ans;
    }
};