class Solution {
public:
    bool check(string s, string s1)
    {
        if(s1.size() > s.size()) return false;

        int i=0, j=0;
        while(j<s1.size())
        {   
            if(s[i]==s1[j])
            {
                i++;
                j++;
            }
            else return false;
        }
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> v;
        stringstream ss(sentence);
        string word;
        while(ss>>word)
        {
           v.push_back(word);
        }
        
        for(int i=0; i<v.size(); i++)
        {
            if(check(v[i],searchWord)) return i+1;
        }
        return -1;
    }
};