#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list> 
#include <unordered_map> 
using namespace std;

// similar to LRU cache, but here we use:
// we chain keys with same frequency in a list, when get(key), we find its position and delete it, reput it in a higher frequency list
// we need to maintain min_frequency and count to evict the LFU key.
//
class LFUCache {
private:
    struct Entry {
        int val, fre;
        list<int>::iterator pos;
    };
    unordered_map<int, Entry> entries;
    unordered_map<int, list<int>> freMap;
    int count, capacity, minfre;
public:
    LFUCache(int capacity) {
        count = minfre = 0;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!entries.count(key)) return -1;
        freMap[entries[key].fre].erase(entries[key].pos); // remove from old bucket
        entries[key].fre++;
        freMap[entries[key].fre].push_front(key); // put into new bucket
        entries[key].pos = freMap[entries[key].fre].begin();
        if (freMap[minfre].empty()) minfre++; // don't forget to update minfre
        return entries[key].val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (get(key) != -1) {
            entries[key].val = value;
        } else {
            if (count == capacity) { // if full, remove the LFU & LRU entry
                entries.erase(freMap[minfre].back());
                freMap[minfre].pop_back();
                --count;
            }
            freMap[1].push_front(key);
            entries[key] = {value, 1, freMap[1].begin()};
            ++count;
            minfre = 1; // don't forget to update minfre
        }
    }
};


int main() {
    return 0;
}
