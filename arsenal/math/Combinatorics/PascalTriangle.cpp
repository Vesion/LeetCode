#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// https://leetcode.com/problems/pascals-triangle-ii/
//
// The kth row of Pascal Triangle is :
//
//      [C(k,0), C(k,1), ..., C(k,k)]
//
// C(k,i) = C(k,i-1) * (k-i+1)/i
//
vector<int> getRow(int rowIndex) {
    vector<int> res(rowIndex+1, 0);
    res[0] = 1;
    for (int i = 1; i <= rowIndex; ++i) {
        res[i] = (long long)res[i-1] * (rowIndex-i+1) / i;
    }
    return res;
}

int main() {
    return 0;
}
