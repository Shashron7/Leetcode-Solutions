class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //dijstra's soln-- from the source node k to all the other nodes present
        //adjacency list
        //dist array = 1e9 then we can say that -1 else we can return the minm time (max time of all nodes)

        vector<pair<int,int>> adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }

 
        vector<int> dist(n+1,1e9);
        

        
        priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq; //pq is formed

        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            int d=temp.first;
            int node=temp.second;


            for(auto it: adj[node])
            {
                if(it.second + d < dist[it.first])
                {
                    dist[it.first]=d+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }

        
        //minm time will be the maxm of the array

        int maxm=0;
        for(int i=1; i<=n; i++)
        {
            maxm=max(maxm,dist[i]);
        }

        return maxm==1e9 ? -1 : maxm;


        
    }
};