class MyHashSet {
    vector<list<int>> arr;
    int prime;
    int hash(int key) {
        return key%prime;
    }
    auto search(int key) {
        int h = hash(key);
        return find(arr[h].begin(), arr[h].end(), key);
    }
public:
    MyHashSet() {
        this->prime = 10006;
        arr.resize(10006);
    }
    
    void add(int key) {
        int h = hash(key);
        if (!contains(key))
            arr[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        auto it = search(key);
        if (it != arr[h].end()) {
            arr[h].erase(it);
        }
    }
    
    bool contains(int key) {
        int h = hash(key);
        return search(key) != arr[h].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */