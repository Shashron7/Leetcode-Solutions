class Solution {
public:
    int bin(int ind, vector<vector<int>>& ev)
    {
        int endtime=ev[ind][1];
        int l=ind+1;
        int r=ev.size()-1;
        int ans=1e9;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(ev[mid][0] > endtime)
            {
                ans=min(ans,mid);
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();

        sort(events.begin(), events.end());

        for(auto it: events) cout<<it[0]<<it[1]<<it[2]<<" ";
        vector<int> maxVR(n,0);

        int maxm=0;
        for(int i=n-1; i>=0; i--)
        {
            maxm=max(maxm,events[i][2]);
            maxVR[i]=maxm;
        }

        for(auto it: maxVR) cout<<it<<" ";

        int ans=0;    
        for(int i=0; i<n; i++)
        {
            int currind=bin(i,events);
            int sum=events[i][2];
            if(currind!=1e9) sum+=maxVR[currind];
            ans=max(ans, sum);


        }
        return ans;
    }
};