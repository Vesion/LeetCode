#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;
        int i = 1, j = n-2;
        while (i < n-1 && arr[i] > arr[i-1]) ++i;
        while (j > 0 && arr[j] > arr[j+1]) --j;
        return i == j+2;
    }
};

int main() {

}