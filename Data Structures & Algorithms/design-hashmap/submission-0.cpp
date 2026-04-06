class MyHashMap {
    vector<list<pair<int, int>>> table;
    int prime_no;
    list<pair<int, int>>::iterator search(int key) {
        int h = hash(key);
        for (auto it = table[h].begin(); it != table[h].end(); ++it) {
            if (it->first == key) {
                return it;
            }
        }
        return table[h].end();
    }
    int hash(int key) {
        return key % prime_no; 
    }

public:
    MyHashMap() {
        this->prime_no = 10007;
        table.resize(10007);
    }
    
    void put(int key, int value) {
        auto it = search(key);
        int h = hash(key);
        if (it != table[h].end()) {
            it->second = value;
            return;
        }
        table[h].push_back({key, value});
    }
    
    int get(int key) {
        int h = hash(key);
        auto it = search(key);
        if (it == table[h].end()) {
            return -1;
        }
        return it->second;
    }
    
    void remove(int key) {
        int h = hash(key);
        auto it = search(key);
        if (it == table[h].end()) {
            return;
        }
        table[h].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */