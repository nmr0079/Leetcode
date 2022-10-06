class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> timeMap;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto &ts = timeMap[key];
        
        //binary search
        int lo = 0;
        int hi = ts.size() - 1;
        int idx = -1;
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(ts[mid].first <= timestamp){
                idx = mid;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        if(idx == -1)
            return "";
        
        return ts[idx].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */