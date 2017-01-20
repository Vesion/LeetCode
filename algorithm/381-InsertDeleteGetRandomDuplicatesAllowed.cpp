#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <unordered_set> 
#include <random> 
using namespace std;

class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> index;
    vector<int> nums;
public:
    RandomizedCollection() { }
    
    bool insert(int val) {
        bool res = !index.count(val);
        nums.push_back(val);
        index[val].insert(nums.size()-1);
        return res;
    }
    
    bool remove(int val) {
        if (!index.count(val)) return false;
        if (val == nums.back()) {
            index[val].erase(nums.size()-1);
            nums.pop_back();
        }
        else {
            int id = *index[val].begin();
            nums[id] = nums.back();
            index[nums.back()].erase(nums.size()-1);
            index[nums.back()].insert(id);
            index[val].erase(id);
            nums.pop_back();
        }
        if (index[val].empty()) index.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};


int main() {
    RandomizedCollection r;
    r.insert(1);
    r.insert(1);
    r.insert(2);
    r.insert(1);
    r.insert(2);
    r.insert(2);

    r.remove(1);
    r.remove(2);
    r.remove(2);
    r.remove(2);
    return 0;
}

