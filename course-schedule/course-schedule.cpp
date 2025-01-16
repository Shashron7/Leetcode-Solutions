class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<int> adj[n];  //adjacency matrix of n 

        vector<int> indegree(n,0);
        for(auto it: prereq)
        {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        vector<int> ans;

        queue<int> q;

        for(int i=0; i<n; i++)
        {
            if(!indegree[i]) q.push(i);
        }

        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            
            ans.push_back(temp);

            for(auto it: adj[temp])
            {
                if(--indegree[it]==0)
                {
                    q.push(it);
                }
            }       
        }

        return ans.size()==n;
        
        




        
    }
};