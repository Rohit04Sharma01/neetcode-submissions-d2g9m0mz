class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> ump;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ump[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (ump.find(key) == ump.end()) return "";

        auto& target = ump[key];
        int low = 0;
        int high = target.size() - 1;
        string result = "";
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target[mid].second <= timestamp) {
                result = target[mid].first;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */