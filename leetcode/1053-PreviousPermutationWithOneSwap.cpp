#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// similar to 031-NextPermutation
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return arr;
        // 1. from back to end, find the first number arr[i] larger than its right neighbor
        int i = n-2;
        for (; i >= 0; --i) {
            if (arr[i] > arr[i+1]) break;
        }
        if (i < 0) return arr;
        // 2. from end to i+1, find the largest number arr[j] smaller than arr[i],
        //    if multiple j found, choose the left most one
        //    [3,1,1,3] -> [1,3,1,3]
        int j = -1;
        for (int k = n-1; k > i; --k) {
            if (j != -1 && arr[k] < arr[j] && arr[j] < arr[i]) break;
            j = k;
        }
        if (j == -1) return arr;
        vector<int> res = arr;
        // 3. swap arr[i] and arr[j]
        swap(res[i], res[j]);
        return res;
    }
};

int main() {
}
