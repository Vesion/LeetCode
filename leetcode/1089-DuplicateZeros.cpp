#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


// Typical problem which should learn to modify array in place.
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        // firstly count how many zeros needed to be inserted to arr.
        // imagine we have a new arr with length equal to length of arr plus zeros needed to be inserted.
        // we can generate new arr by put numbers from arr and extra zeros into it
        // actually we don't need a real new arr, just an index j pointing to the end of the new arr,
        // then we can put numbers from back to start.
        int j = n-1 + count(arr.begin(), arr.end(), 0);
        for (int i = n-1; i >= 0; --i, --j) {
            if (j < n) arr[j] = arr[i];
            if (arr[i] == 0) {
                if (--j < n) arr[j] = 0;
            }
        }
    }
};

int main() {

}