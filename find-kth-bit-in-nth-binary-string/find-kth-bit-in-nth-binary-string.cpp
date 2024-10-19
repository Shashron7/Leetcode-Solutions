class Solution {
public:
    string invert(string &s)
    {
        string ans="";
        for(auto it: s)
        {
            if(it=='0') ans+='1';
            else ans+='0';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    char findKthBit(int n, int k) {
        string prev="0";
        int num=n-1;
        while(num--)
        {
            string news=prev+"1"+invert(prev);
            prev=news;
            
        }

       return prev[k-1];
        

    }
};