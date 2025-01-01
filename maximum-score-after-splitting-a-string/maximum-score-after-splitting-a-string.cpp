class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        vector<int> z(n,0);
        vector<int> o(n,0);

        int zeroes=0;
        for(int i=0; i<n; i++)
        {
            if(i!=0)
            {
                z[i]=zeroes;
            }
            if(s[i]=='0') zeroes++;
        }

        int ones=0;
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]=='1') ones++;
            o[i]=ones;
            
        }

        

        for(auto it: z) cout<<it<<" ";
        cout<<endl;

        for(auto it: o) cout<<it<<" ";

        int ans=0;
        
        for(int i=1; i<n; i++)
        {
            ans=max(ans,z[i]+o[i]);
        }  

        return ans;
    }
};