#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() != unordered_set<int>(nums.begin(), nums.end()).size();
    }
};


int main() {
    return 0;
}
