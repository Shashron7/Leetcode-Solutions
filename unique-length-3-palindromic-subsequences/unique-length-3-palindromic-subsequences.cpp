class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int ans=0;
        for(int i=0; i<26; i++)
        {
            int curr=i+'a';
            set<int> vis;
            int f=-1;
            int l=-1;

            for(int j=0; j<s.size(); j++)
            {
                if(s[j]==curr)
                {
                    f=j;
                    break;
                }
            }

            for(int j=s.size()-1; j>=0; j--)
            {
                if(s[j]==curr && j>f)
                {
                    l=j;
                    break;
                }
            }

            if(f!=-1 && l!=-1 && f!=l)
            {
                unordered_set<char> vis;
                int count=0;
                for(int j=f+1; j<l; j++)
                {

                    if(vis.find(s[j])==vis.end())
                    {
                        vis.insert(s[j]);
                        count++;
                    }

                }
                ans+=count;
            }

            

            
        }
        return ans;
    }
};