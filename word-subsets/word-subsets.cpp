class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n=words1.size();

        vector<vector<int>> mat(n, vector<int>(26,0));

        for(int i=0; i<n; i++)
        {
            for(auto ch: words1[i])
            {
                mat[i][ch-'a']++;
            }
        }

        vector<int> v(26, 0);
        for(auto it : words2)
        {
            vector<int> curr(26,0);
            for(auto ch : it)
            {
                curr[ch-'a']++;
            }

            for(int i=0; i<26; i++)
            {
                v[i]=max(v[i],curr[i]);
            }
        }

        for(auto it : v) cout<<it<<" ";

        vector<string> ans;
        for(int i=0; i<n; i++)
        {
            bool check=true;

            for(int j=0; j<26; j++)
            {
                if(v[j])
                {
                    if(v[j] > mat[i][j])
                    {
                        check=false;
                        break;
                    }
                }
            }
            if(check) ans.push_back(words1[i]);
        }

        return ans;
    }
};