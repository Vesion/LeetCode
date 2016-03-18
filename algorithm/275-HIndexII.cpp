#include <iostream>
#include <vector>
using namespace std;

// based on 274-HIndex, the citations array has been sorted in ascending order
// The basic idea is to find the minimum index such that
//      citations[index] >= citations.size() - index
// When find the index, then the H-index is citations.size()-index, the process is very like std::lower_bound

// Solution 1 : one pass, O(n) time
int hIndex_On(vector<int>& citations) {
    int n = citations.size();
    int h = n;
    for (int i = 0; i < n; ++i) {
        if (citations[i] >= h) break;
        --h;
    }
    return h;
}


// Solution 2 : binary search, O(lgn) time
int hIndex_Olgn(vector<int>& citations) {
    int n = citations.size();
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right-left)/2;
        if (citations[mid] == n-mid) return n-mid;
        else if (citations[mid] > n-mid) right = mid;
        else left = mid+1;
    }
    return n-right;
}

int main() {
    vector<int> citations = {2, 2, 2};
    cout << hIndex_On(citations) << endl;
    cout << hIndex_Olgn(citations) << endl;
    return 0;
}
