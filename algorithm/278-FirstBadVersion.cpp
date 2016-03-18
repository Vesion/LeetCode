#include <iostream>
#include <vector>
using namespace std;

bool isBadVersion(int i) {
    return i >= 1;
}


int firstBadVersion(int n) {
    int left = 1, right = n;
    while (left <= right) {
        int mid = left + (right-left)/2;
        if (isBadVersion(mid)) right = mid-1;
        else left = mid+1;
    }
    return left;
}

int main() {
    cout << firstBadVersion(1) << endl;
    return 0;
}
