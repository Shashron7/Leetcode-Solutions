class Solution {
public:
    int check(string s, string curr)
    {
        int n=curr.size();
        int count=0;
        for(int i=0; i<=s.size()-n; i++)
        {
            string sub=s.substr(i,n);
            if(sub==curr) count++;

        }
        return count;
    }
    int maximumLength(string s) {
        int n=s.size();
        int ans=-1;
        for(int i=0; i<26; i++)
        {
            int currchar=i+'a';
            for(int i=n; i>=1; i--)
            {
                string curr="";
                for(int x=0; x<i; x++)
                {
                     curr+=currchar;
                    
                }
                
                if(check(s,curr)>=3)
                {
                    ans=max(ans,i);
                }
            }
            
            

        }
        return ans;
    }
};