class Solution {
public: unordered_set<char> vis={'a', 'e', 'i', 'o', 'u'};
    bool check(string s)
    {
        int n=s.size();
        return (vis.find(s[0])!=vis.end() && vis.find(s[n-1])!=vis.end());
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> v(n,0);
        vector<int> pre(n,0);


        for(int i=0; i<n; i++)
        {
            if(check(words[i])) v[i]=1;
            
        }
        pre[0]=v[0];
        for(int i=1; i<n; i++)
        {
            pre[i]=pre[i-1]+v[i];
        }
    

        vector<int> ans;

        for(auto it : queries)
        {
            int curr=(it[0]==0 ? pre[it[1]] : pre[it[1]]-pre[it[0]-1]);
            ans.push_back(curr);
        }

        return ans;

    }
};