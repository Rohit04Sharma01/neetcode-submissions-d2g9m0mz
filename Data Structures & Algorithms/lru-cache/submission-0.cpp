class LRUCache {
private:
    int cache_size;

    // key -> value
    unordered_map<int, int> cache;

    // key -> iterator in list
    unordered_map<int, list<int>::iterator> order;

    // stores keys in LRU order
    list<int> l;

public:
    LRUCache(int capacity) {
        cache_size = capacity;
    }

    int get(int key) {

        if (cache.find(key) == cache.end()) {
            return -1;
        }

        // move key to most recently used
        l.erase(order[key]);
        l.push_back(key);
        order[key] = prev(l.end());

        return cache[key];
    }

    void put(int key, int value) {

        // key already exists
        if (cache.find(key) != cache.end()) {

            l.erase(order[key]);

        }
        // capacity full
        else if (cache.size() == cache_size) {

            int lru = l.front();

            l.pop_front();

            cache.erase(lru);
            order.erase(lru);
        }

        // insert new / updated key
        l.push_back(key);

        order[key] = prev(l.end());

        cache[key] = value;
    }
};