#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class SVNRepo {
public:
    static bool isBadVersion(int k) {
        return k >= 2;
    }
};

/*
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/

class Solution {
public:
    int findFirstBadVersion(int n) {
        if (n < 1) return 0;
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (SVNRepo::isBadVersion(mid)) {
                if (mid == 1 || !SVNRepo::isBadVersion(mid-1)) return mid;
                right = mid-1;
            } else
                left = mid+1;
        }
        return 0;
    }
};

int main() {
    Solution s;
    cout << s.findFirstBadVersion(2) << endl;
    return 0;
}
