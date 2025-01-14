class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
    vector<int> ans;
    vector<int> freq1(51,0), freq2(51,0);

    for(int i=0; i<a.size(); i++)
    {
        freq1[a[i]]++;
        freq2[b[i]]++;

        int count=0;
        for(int j=0; j<51; j++)
        {
            if(freq1[j] >0 && freq2[j] > 0) count++;
        }
        ans.push_back(count);
    }
    return ans;
    
        
    }
};