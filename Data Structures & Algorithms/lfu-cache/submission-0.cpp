#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
private:
    struct Node {
        int key;
        int value;
        int freq;

        list<int>::iterator it; // position in bucket

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> cache;

    // freq -> keys (LRU order)
    unordered_map<int, list<int>> bucket;

    void updateFreq(Node* node) {
        int oldFreq = node->freq;

        // remove from old freq bucket in O(1)
        bucket[oldFreq].erase(node->it);

        // if old bucket empty
        if (oldFreq == minFreq &&
            bucket[oldFreq].empty()) {
            minFreq++;
        }

        node->freq++;

        // insert at front (most recently used)
        bucket[node->freq].push_front(node->key);

        // save iterator
        node->it = bucket[node->freq].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        Node* node = cache[key];
        updateFreq(node);

        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        // already exists
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        // cache full -> evict LFU + LRU
        if (cache.size() == capacity) {
            int removeKey = bucket[minFreq].back();
            bucket[minFreq].pop_back();

            delete cache[removeKey];
            cache.erase(removeKey);
        }

        // new node
        Node* node = new Node(key, value);

        bucket[1].push_front(key);
        node->it = bucket[1].begin();

        cache[key] = node;
        minFreq = 1;
    }
};