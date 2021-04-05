#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i += 2) {
            int f = nums[i], num = nums[i+1];
            while (f--) res.push_back(num);
        }
        return res;
    }
};

int main() {

}