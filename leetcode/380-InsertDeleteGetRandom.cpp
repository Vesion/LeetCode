#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>
using namespace std;

class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int,int> m;

    RandomizedSet() {}

    bool insert(int val) {
        if (m.count(val)) return false;
        nums.push_back(val);
        m[val] = nums.size()-1;
        return true;
    }

    bool remove(int val) {
        auto it = m.find(val);
        if (it == m.end()) return false;
        int i = it->second;
        m[nums.back()] = i;
        swap(nums[i], nums.back());
        nums.pop_back();
        m.erase(it);
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
