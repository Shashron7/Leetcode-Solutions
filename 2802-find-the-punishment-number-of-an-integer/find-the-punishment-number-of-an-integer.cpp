class Solution {
public:
    bool func(int ind, string& s, int target, int prev, int currsum)
    {   
        if(ind==s.size()-1)
        {
            string curr=s.substr(prev,ind-prev+1);
            int num=stoi(curr);
            return (currsum+num==target);
            
        }
        bool take=false, nottake=false;
        string curr=s.substr(prev,ind-prev+1);
        int num=stoi(curr);
        take=func(ind+1,s,target,ind+1,currsum+num);
        nottake=func(ind+1,s,target,prev,currsum);
        return take|nottake;
    }
    int punishmentNumber(int n) {
        if(n==1) return 1;
        int ans=0;
        for(int i=2; i<=n; i++)
        {
            string s=to_string(i*i);
            int curr=func(0,s,i,0,0);
            if(curr) ans+=i*i;
        }
        return ans+1;
    }
};