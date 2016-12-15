#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <list> 
#include <random> 
using namespace std;

class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int, list<int>> index;

public:
    RandomizedCollection() { }

    bool insert(int val) {
        bool r = index.count(val);
        nums.push_back(val);
        index[val].push_back(nums.size()-1);
        return !r;
    }
    
    bool remove(int val) {
        if (!index.count(val)) return false;
        int n = nums.size();
        int id = index[val].back();
        if (id < n-1) {
            nums[id] = nums[n-1];
            index[nums[n-1]].pop_back();
            index[nums[n-1]].push_front(id);
        }
        nums.pop_back();
        index[val].pop_back();
        if (index[val].empty()) index.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};


int main() {
    RandomizedCollection rs;
    cout << rs.insert(10) <<endl;;
    cout << rs.insert(10) <<endl;;
    cout << rs.insert(20) <<endl;;
    cout << rs.insert(20) <<endl;;
    cout << rs.insert(30) <<endl;;
    cout << rs.insert(30) <<endl;;
    cout << rs.remove(10) <<endl;;
    cout << rs.remove(10) <<endl;;
    cout << rs.remove(30) <<endl;;
    cout << rs.remove(30) <<endl;;
    cout <<rs.getRandom() <<endl;
    cout <<rs.getRandom() <<endl;
    return 0;
}

