#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
#include <random> 
using namespace std;

class RandomizedSet {
private:
    unordered_set<int> s;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (s.count(val)) return false;
        s.insert(val);    
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return s.erase(val);
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int rid = rand() % s.size();
        auto bit = s.begin();
        while (rid-- > 0) ++bit;
        return *bit;
    }
};


int main() {
    RandomizedSet rs;
    return 0;
}
