class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size()) return false;

        map<char,int> mp;
        for(auto it: s)
        {
            mp[it]++;
        }

        int odd=0;
        for(auto it: mp)
        {
            if(it.second%2!=0) odd++;
        }

        return !(odd > k);
    }
};