class Solution {
public:
    bool func(string s, string g, int ind)
    {
        int i=0, j=ind;
        int n=g.size();
        while(i<s.size())
        {
            if(s[i]!=g[j]) return false;
            i++;
            j=(j+1)%n;
        }
        return true;
    }
    bool rotateString(string s, string goal) {
       if(s.size()!=goal.size()) return false;

       char start=s[0];
       vector<int> ch;
       for(int i=0; i<goal.size(); i++)
       {
            if(goal[i]==start) ch.push_back(i);
       }

       for(auto it: ch)
       {
            if(func(s,goal,it)) return true;
       }

        return false;
        
    }
};