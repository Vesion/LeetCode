#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Based on 274-HIndex solution 1.
// From right to left, find the first one citations[i] < n-i, but O(n) is trivial, so we use bianry search to get O(logn) time
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        int n = citations.size();
        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (citations[mid] >= n-mid) right = mid;
            else left = mid+1;
        }
        return n-right;
    }
};


int main() {
    return 0;
}
