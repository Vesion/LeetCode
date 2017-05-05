#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0, res = 0;
        for (int& num : nums) {
            sum += num;
            if (m.count(sum-k)) res += m[sum-k];
            m[sum]++;
        }
        return res;
    }
};


int main() {
    return 0;
}
