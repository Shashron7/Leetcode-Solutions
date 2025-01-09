class Solution {
public:

    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        int n=pref.size();
        for(auto it: words)
        {
            if(it.size() >=n)
            {
                string curr=it.substr(0,n);
                if(curr==pref) count++;
            }
        }
        return count;
    }
};