#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int cap;
    list<int> lru;
    unordered_map<int, pair<int, list<int>::iterator>> mpp; 
    

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1; 
        }
        
        lru.erase(mpp[key].second);
        lru.push_front(key);
        mpp[key].second = lru.begin();
        return mpp[key].first;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            
            lru.erase(mpp[key].second);
        }
        else if ((int)lru.size() == cap) {
            
            int lruKey = lru.back();
            lru.pop_back();
            mpp.erase(lruKey);
        }
        
        lru.push_front(key);
        mpp[key] = {value, lru.begin()};
    }
};
