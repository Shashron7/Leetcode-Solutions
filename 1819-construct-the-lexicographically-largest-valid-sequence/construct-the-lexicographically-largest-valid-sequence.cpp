class Solution {
public:

    bool func(int ind, vector<int>& vis, vector<int>& ans, vector<int>& v, int n)
    {
         if (ind == v.size()) {
            ans = v; // Store the valid sequence
            return true; // Stop further exploration
        }

        if (v[ind] != 0) {
            // If the current position is already filled, move to the next position
            return func(ind + 1, vis, ans, v, n);
        }

        // Try placing the largest possible number first
        for (int i = n; i >= 1; i--) {
            if (vis[i]) continue; // Skip if the number is already used

            if (i == 1) {
                // Place 1 at the current position
                vis[i] = 1;
                v[ind] = 1;
                if (func(ind + 1, vis, ans, v, n)) {
                    return true; // Stop if a valid sequence is found
                }
                // Backtrack
                vis[i] = 0;
                v[ind] = 0;
            } else {
                // For numbers > 1, ensure the second position is available
                if (ind + i < v.size() && v[ind + i] == 0) {
                    vis[i] = 1;
                    v[ind] = i;
                    v[ind + i] = i;
                    if (func(ind + 1, vis, ans, v, n)) {
                        return true; // Stop if a valid sequence is found
                    }
                    // Backtrack
                    vis[i] = 0;
                    v[ind] = 0;
                    v[ind + i] = 0;
                }
            }
        }

        return false; // No valid number could be placed at this position
    }
    

    vector<int> constructDistancedSequence(int n) {
        
        

        int size=2*(n-1)+1;

        vector<int> v(size,0); // vector array an

        vector<int> vis(n+1,0); // from 1 to n

        
        
        vector<int> ans;

        int a=func(0,vis,ans,v,n);
        return ans;

    }
};