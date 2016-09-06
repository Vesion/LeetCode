#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// The classical shuffle algorithm: Fisher Yates Algorithm
class Solution {
private:
    vector<int> nums;

public:
    Solution(vector<int> nums) {
        this->nums = nums;        
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        auto c = nums;
        for (int i = 0; i < (int)c.size(); ++i) {
            int j = rand() % (c.size() - i);
            swap(c[i], c[i+j]);
        }
        return c;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s(nums);
    s.shuffle();
    s.shuffle();
    s.shuffle();
    auto r = s.reset();
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
