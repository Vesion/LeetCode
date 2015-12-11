#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int len = nums.size();
    if (len == 0)
        return 0;
    int first = 0, last = len;
    while (first < last) {
        int mid = first + (last - first) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] > target)
            last = mid;
        else
            first = mid + 1;
    }
    return first;
}

int main() {
    vector<int> a{1, 2, 5, 8, 10};
    cout << searchInsert(a, 11) << endl;
    return 0;
}
