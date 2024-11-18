class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> copy=code;
        for(auto it: code) copy.push_back(it);
        vector<int> pre(copy.size());
        pre[0]=copy[0];
        for(int i=1; i<copy.size(); i++)
        {
            pre[i]=copy[i]+pre[i-1];
        }

        vector<int> ans;
        if(k==0)
        {
            vector<int> v(code.size(),0);
            return v;
        }
        else if(k>0)
        {
            for(int i=0; i<code.size(); i++)
            {
                int curr=pre[i+k]-pre[i];
                ans.push_back(curr);
            }
        }
        else
        {
            for(int i=code.size(); i<copy.size(); i++)
            {
                int curr=pre[i-1]-pre[i+k-1];
                ans.push_back(curr);
            }
        }
        return ans;


    }
};