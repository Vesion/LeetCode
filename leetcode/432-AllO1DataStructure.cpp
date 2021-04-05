#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class AllOne {
    struct Bucket {
        int count;
        unordered_set<string> keys;
        Bucket(int c) : count(c) {}
        Bucket(int c, const string& k) {
            count = c;
            keys.insert(k);
        }
    };
    list<Bucket> l;
    unordered_map<string, list<Bucket>::iterator> m;

public:
    /** Initialize your data structure here. */
    AllOne() {  }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!m.count(key)) m[key] = l.insert(l.begin(), {0, key});
        auto it = m[key];
        auto nit = next(it);
        if (nit == l.end() || it->count+1 < nit->count) {
            nit = l.insert(nit, {it->count+1});
        }
        nit->keys.insert(key);
        m[key] = nit;
        it->keys.erase(key);
        if (it->keys.empty()) l.erase(it);
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!m.count(key)) return;
        auto it = m[key];
        auto pit = prev(it);
        m.erase(key);
        if (it->count > 1) {
            if (it == l.begin() || it->count-1 > pit->count) {
                pit = l.insert(it, {it->count-1});
            }
            pit->keys.insert(key);
            m[key] = pit;
        }
        it->keys.erase(key);
        if (it->keys.empty()) l.erase(it);
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return l.empty() ? "" : *l.back().keys.begin();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return l.empty() ? "" : *l.front().keys.begin();
    }
};


int main() {
}
