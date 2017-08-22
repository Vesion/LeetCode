#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Find minimum difference, Page 337
// Given two sorted array, find the minimum difference of two number a and b, a is from array1 and b is from array2

int findMinDiff(vector<int>& a, vector<int>& b) {
    int m = a.size(), n = b.size();

    // merge into c array
    vector<pair<int,int>> c(m+n);
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) c[k++] = {a[i++], 0};
        else c[k++] = {b[j++], 1};
    }
    while (i < m) c[k++] = {a[i++], 0};
    while (j < n) c[k++] = {b[j++], 1};

    // iterate c, if two adjacent elements are from different array, update result
    int res = INT_MAX;
    for (int i = 1; i < m+n; ++i) {
        if (c[i].second != c[i-1].second)
            res = min(res, abs(c[i].first-c[i-1].first));
    }
    return res;
}



int main() {
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {6, 7, 8, 9};
    cout << findMinDiff(a, b) << endl;
    return 0;
}
