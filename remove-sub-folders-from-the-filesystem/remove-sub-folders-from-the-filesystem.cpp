class Solution {
public:
    
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        // for(auto it: folder) cout<<it<<" ";
        unordered_set<string> vis;    
        vector<string> ans;    
        for(auto it: folder)
        {
            string curr="";
            bool check=true;
            for(int i=0; i<it.size(); i++)
            {
                while(i<it.size() && it[i]!='/')
                {
                    curr+=it[i];
                    i++;
                }
                curr+='.';
                cout<<"curr is "<<curr<<endl;
                if(vis.find(curr)!=vis.end())
                {
                    check=false;
                    break;
                }

            }
            if(check)
            {
                 ans.push_back(it);
                 vis.insert(curr);
            }
        }
        return ans;


        
        return {};
    }
};