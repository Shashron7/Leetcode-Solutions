class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //terminal node- no outgoing edges

        //reverse the edges

        // start from the terminal nodes
        int n=graph.size();

        vector<int> adj[n];

        vector<int> indegree(n,0);

        for(int i=0; i<graph.size(); i++)
        {
            for(auto it: graph[i])
            {
                adj[it].push_back(i);
            }
        }

        for(int i=0; i<n; i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(!indegree[i]) //starting from the end nodes --indegree is 0
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : adj[node])
            {
                if(--indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};