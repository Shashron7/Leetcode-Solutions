class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //window that doesnt have repeating characters

        //variable to store the maximum 

        int l=0;
        unordered_set<char> vis;

        int ans=0;
        for(int r=0; r<s.size(); r++)
        {
            while(vis.find(s[r])!=vis.end())
            {
                vis.erase(s[l]);
                l++;
            }
            vis.insert(s[r]);
            ans=max(ans,r-l+1);
        }
        
        return ans;
    }
};