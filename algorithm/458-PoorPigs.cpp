#include <iostream>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log(buckets) / log(minutesToTest/minutesToDie+1));
    }
};

int main() {
    Solution s;
    cout << s.poorPigs(1000, 15, 60);
    return 0;
}
