class TopVotedCandidate {
public:
    vector<int>time;
    vector<int>ans;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        time = times;
        int mxp = -1;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[persons[i]]++;
            if(mp[persons[i]] >= mp[mxp]){
                mxp = persons[i];
            }
            ans.push_back(mxp);
        }
    }
    
    int q(int t) {
       
       int l=0, r=time.size()-1;

       int ind=0;
       while(l<=r)
       {
            int mid=(l+r)>>1;
            if(time[mid]> t)
            {
                r=mid-1;
            }
            else
            {
                ind=max(ind,mid);
                l=mid+1;
            }
       }

       return ans[ind];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */