class Solution {
public:
   vector<int> bfs(int V, vector<int> adj[], int src) {
    vector<int> dist(V, INT_MAX);
    queue<int> q;
    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int adjnode : adj[node]) {
            if (dist[node] + 1 < dist[adjnode]) {
                dist[adjnode] = dist[node] + 1;
                q.push(adjnode);
            }
        }
    }
    return dist;
}
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        adj[i].push_back(i + 1);
    }

    vector<int> dist = bfs(n, adj, 0);
    vector<int> ans;

    for (auto& query : queries) {
        int u = query[0], v = query[1];
        adj[u].push_back(v);

        if (dist[u] + 1 < dist[v]) {
            dist[v] = dist[u] + 1;
            queue<int> q;
            q.push(v);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int adjnode : adj[node]) {
                    if (dist[node] + 1 < dist[adjnode]) {
                        dist[adjnode] = dist[node] + 1;
                        q.push(adjnode);
                    }
                }
            }
        }

        ans.push_back(dist[n - 1]);
    }
    return ans;
        
        
    }
};