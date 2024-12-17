class Solution {
public:
    void func(string& s, int num, int ind)
    {
        for(int i=0; i<num; i++) s+= ind+'a';
        
    }
    string repeatLimitedString(string s, int rl) {
        vector<int> v(26,0);
        for(auto it: s) v[it-'a']++;

        priority_queue<int> pq; //max heap
        string ans="";

       
        for(int i=0; i<v.size(); i++)
        {
            if(v[i]) pq.push(i);
        }
        
        while(!pq.empty())
        {
            int temp=pq.top();
            pq.pop();
            if(v[temp] <= rl)
            {
                func(ans,v[temp],temp);
            }
            else
            {
                func(ans,rl,temp);
                v[temp]-=rl;
                if(pq.empty()) break;
                int next=pq.top();
                func(ans,1,next);
                v[next]-=1;
                if(!v[next]) pq.pop();
                pq.push(temp);

            }
        }
        return ans;
    }
};