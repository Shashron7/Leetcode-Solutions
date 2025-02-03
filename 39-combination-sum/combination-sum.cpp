class Solution {
public:

    void func(int ind, vector<int>& cand, int target, vector<int>& v,  vector<vector<int>>& ans)
    {
        if(target < 0 || ind==cand.size()) return ;
        if(target == 0)
        {   
            ans.push_back(v);
            return; 
        }
        
        v.push_back(cand[ind]);
        func(ind,cand,target-cand[ind],v,ans);
        v.pop_back();
        func(ind+1,cand,target,v,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        vector<int> v;

        func(0,candidates,target,v,ans);
        return ans;
    }
};