class Solution {
public:
    long long sum(int node, vector<int> adj[], vector<int>& vis,  vector<int>& values,vector<long long>& sumSub) //calculate the sum of each subtree and store it in a vector 
    {
        vis[node]=1;
        long long currsum=values[node];

        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                currsum+=1LL*sum(it,adj,vis,values,sumSub);
            }
        }
        return sumSub[node]=currsum;
    }
    void func(int node, vector<int> adj[], vector<int>&vis, vector<int>& values, vector<long long>&sumSub, int k, int& ans)
    {
        vis[node]=1;
        if(sumSub[node]%k==0) ans++;

        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                func(it,adj,vis,values,sumSub,k,ans);
            }
        }
        

    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> adj[n];
        
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        vector<long long> sumSub(n,-1);
        int a= sum(0,adj,vis,values,sumSub);
        for(auto it: sumSub) cout<<it<<" ";
        int ans=0;
        vector<int> v(n,0);
        func(0,adj,v,values,sumSub,k,ans);
        return ans;


    }
};