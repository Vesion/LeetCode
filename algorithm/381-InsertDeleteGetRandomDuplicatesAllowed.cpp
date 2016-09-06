#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
using namespace std;

class RandomizedCollection {
private:
    multiset<int> s;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if (!s.count(val)) {
            s.insert(val);    
            return true;
        }
        s.insert(val);
        return false;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it = s.find(val);
        if (it != s.end()) {
            s.erase(it);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int rid = rand() % s.size(); 
        auto it = s.begin();
        while (rid-- > 0) it++;
        return *it;
    }
};

int main() {
    
    return 0;
}
