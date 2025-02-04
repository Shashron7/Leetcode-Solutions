class TimeMap {
public:
    typedef pair<int, string> pis;
    unordered_map<string, vector<pis>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        const vector<pis>& temp = map[key];

        int lo=0, hi=temp.size()-1; string ans="";
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;

            if(temp[mid].first == timestamp){
                return temp[mid].second;
            }
            else if(temp[mid].first < timestamp){
                ans = temp[mid].second;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */