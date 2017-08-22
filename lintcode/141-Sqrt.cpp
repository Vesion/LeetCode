#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if (x <= 1) return x;
        int left = 1, right = x/2;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (x/mid == mid) return mid;
            if (x/mid > mid) left = mid+1;
            else right = mid-1;
        }
        return left-1;
    } 
};

int main() {
    Solution s;
    cout << s.sqrt(1) << endl;
    cout << (int)std::sqrt(1) << endl;
    return 0;
}
