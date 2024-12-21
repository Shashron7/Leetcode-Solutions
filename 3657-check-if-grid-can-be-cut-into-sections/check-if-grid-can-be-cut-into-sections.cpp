class Solution {
public:
    bool func(vector<vector<int>>& v)
    {
        int ans=0;
        int maxm=0;
        for(int i=0; i<v.size(); i++)
        {
            if(i!=0)
            {
                if(v[i][0] >=maxm) ans++;
            }
            maxm=max(maxm, v[i][1]);
            if(ans==2) return true;
        }

        return ans==2;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x, y;

        for(auto it: rectangles)
        {
            x.push_back({it[0], it[2]});
            y.push_back({it[1], it[3]});
        }

        sort(y.begin(), y.end());
        sort(x.begin(), x.end());
        // return 0;

        return func(y) || func(x) ;
    }

};