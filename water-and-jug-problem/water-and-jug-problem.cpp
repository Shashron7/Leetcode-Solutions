class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        vector<int> v={0,0};
        queue<pair<int,int>> q;
        q.push({0,0});
        set<pair<int,int>> vis;
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            int f=temp.first;
            int s=temp.second;
            if(vis.find(temp)!=vis.end()) continue;
            if(f+s==target) return true;
            vis.insert({f,s});
            q.push({x,s});
            q.push({f,y});
            q.push({0,s});
            q.push({f,0});
            if(y-s>0) //if I can put something
            {
                int put=min(y-s,f);
                q.push({f-put,s+put});
            }
            if(x-f>0)
            {
                int put=min(x-f,s);
                q.push({f+put,s-put});
            }


            





        }
        return false;

        
    }
};