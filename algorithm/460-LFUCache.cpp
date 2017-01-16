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
    int capacity, count, minfre;
    unordered_map<int, Entry> entry;
    unordered_map<int, list<int>> freMap;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        count = minfre = 0;
    }
    
    int get(int key) {
        if (!entry.count(key)) return -1;
        int fre = entry[key].fre;
        freMap[fre].erase(entry[key].pos); // remove from old fre bucket

        entry[key].fre = fre = fre+1; // update fre

        freMap[fre].push_back(key); // put into new fre bucket
        entry[key].pos = --freMap[fre].end(); // update position

        if (freMap[minfre].empty()) minfre++; // ! check if minfre bucket is empty
        return entry[key].val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (get(key) != -1) {
            entry[key].val = value;
        } else {
            if (count == capacity) {
                int ek = freMap[minfre].front();
                entry.erase(ek);
                freMap[minfre].pop_front();
                --count;
            }
            freMap[1].push_back(key);
            entry[key] = {value, 1, --freMap[1].end()};
            minfre = 1; // ! don't forget to reset minfre to 1
            ++count;
        }
    }
};


int main() {
    return 0;
}
