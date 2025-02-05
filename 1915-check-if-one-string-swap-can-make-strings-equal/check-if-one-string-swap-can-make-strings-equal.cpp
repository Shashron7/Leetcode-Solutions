class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        if(s1 == s2 ) return true;

        vector<int> v1(26,0), v2(26,0);

        for(auto it:  s1) v1[it-'a']++;

        for(auto it: s2) v2[it-'a']++;

        if(v1 != v2) return false;

        int count=0;
        for(int i=0; i<s1.size(); i++)
        {
            if(s1[i]!=s2[i]) count++;

            if(count > 2) return false; 
        }

        return count==2;
    }
};