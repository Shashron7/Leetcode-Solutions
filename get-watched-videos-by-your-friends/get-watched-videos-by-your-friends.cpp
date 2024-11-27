class Solution {
public:

    static bool comp(string a, string b, map<string, int>& mp) {
        if (mp[a] != mp[b]) {
            return mp[a] < mp[b]; // Sort by frequency
        }
        return a < b; // If frequencies are the same, sort alphabetically
    }

    vector<string> watchedVideosByFriends(vector<vector<string>>& wv, vector<vector<int>>& f, int id, int level) {
        vector<string> ans;
        int n = wv.size();
        vector<vector<int>> adj(n);       
        for (int i = 0; i < n; i++) {
            for (auto it : f[i]) {
                adj[i].push_back(it);
            }
        }

        queue<pair<int, int>> q;
        q.push({0, id});  // Start from the user with id
        vector<bool> visited(n, false);  // Track visited nodes
        visited[id] = true;
        map<string, int> mp;

        // BFS to find friends at the exact level
        while (!q.empty()) {
            int dist = q.front().first;
            int node = q.front().second;
            q.pop();

            if (dist == level) {
                // Only count videos for friends at the target level
                for (auto s : wv[node]) {
                    mp[s]++;
                }
            }

            if (dist < level) {
                for (auto it : adj[node]) {
                    if (!visited[it]) {
                        visited[it] = true;
                        q.push({dist + 1, it});
                    }
                }
            }
        }

        // Collect the videos and sort them
        for (auto it : mp) {
            ans.push_back(it.first);
        }
        
        sort(ans.begin(), ans.end(), [&mp](const string& a, const string& b) {
            return comp(a, b, mp);
        });

        return ans;
    }
};