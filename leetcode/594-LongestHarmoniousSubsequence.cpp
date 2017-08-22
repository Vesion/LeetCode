#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> m;
        for (int& num : nums) m[num]++;
        int res = 0;
        for (auto& p : m) {
            if (m.count(p.first-1)) res = max(res, m[p.first-1]+p.second);
        }
        return res;
    }
};


int main() {
    return 0;
}
