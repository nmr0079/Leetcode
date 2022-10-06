class TimeMap {
public:
    unordered_map<string,map<int,string>> timeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
       // auto &ts = timeMap[key];
        auto itr = timeMap[key].upper_bound(timestamp);
        if(itr == timeMap[key].begin())
            return "";
        itr--;
        return itr->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */