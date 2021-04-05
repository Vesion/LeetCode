#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res = nums;
        for (int i = 0, j = res.size()-1; i < j; ) {
            while (i < j && ((res[i]&1) == 0)) ++i;
            while (i < j && ((res[j]&1) == 1)) --j;
            if (i < j) swap(res[i++], res[j--]);
        }
        return res;
    }
};

int main() {
}
