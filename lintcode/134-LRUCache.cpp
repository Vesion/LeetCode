#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list> 
#include <unordered_map> 
using namespace std;

class LRUCache{
private:
    struct LRUNode {
        int key, val;
        LRUNode(int k, int v) : key(k), val(v) {}
    };
    list<LRUNode> cacheList;
    unordered_map<int, list<LRUNode>::iterator> cacheMap;
    size_t capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!cacheMap.count(key)) return -1;
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        return cacheMap[key]->val;
    }

    void set(int key, int value) {
        if (cacheMap.count(key)) {
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
            cacheMap[key]->val = value;
        } else {
            if (cacheMap.size() == capacity) {
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(LRUNode(key, value));
            cacheMap[key] = cacheList.begin();
        }
    }
};

int main() {
    LRUCache lru(3); 
    lru.set(1,1);
    cout << lru.get(1) << endl;
    return 0;
}
