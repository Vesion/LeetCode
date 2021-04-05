#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


// Straight forward, O(n)
class Solution0 {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int res = 1;
        for (int num : arr) {
            if (num > res) {
                if (num-res < k) {
                    k -= (num-res);
                    res = num+1;
                } else {
                    res += k-1;
                    k = 0;
                    break;
                }
            } else {
                res = num+1;
            }
        }
        if (k) res += k-1;
        return res;
    }
};


// Binary serach, O(logn)
// search i, arr[i] = i+k+1
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lower = 0, upper = arr.size();
        while (lower < upper) {
            int mid = lower + (upper-lower)/2;
            if (arr[mid]-1-mid < k) lower = mid+1;
            else upper = mid;
        }
        return lower+k;
    }
};


int main() {

}
