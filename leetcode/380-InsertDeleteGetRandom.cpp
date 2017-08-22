#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <random> 
using namespace std;

class RandomizedSet {
private:
    vector<int> nums; // array ensures O(1) random access
    unordered_map<int, int> index; // hash table ensures O(1) insert and delete

public:
    RandomizedSet() { }

    bool insert(int val) {
        if (index.count(val)) return false;
        nums.push_back(val);
        index[val] = nums.size()-1;
        return true;
    }
    
    // find position of val, let it hold the last number, then pop the last number
    bool remove(int val) {
        if (!index.count(val)) return false;
        int id = index[val];
        nums[id] = nums.back();
        index[nums.back()] = id;
        nums.pop_back();
        index.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};


int main() {
    RandomizedSet rs;
    cout << rs.insert(0) <<endl;;
    cout << rs.insert(1) <<endl;;
    cout << rs.remove(0) <<endl;;
    cout << rs.insert(2) <<endl;;
    cout << rs.remove(1) <<endl;;
    cout <<rs.getRandom() <<endl;
    return 0;
}
