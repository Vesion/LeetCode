#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int len = nums.size();
    vector<int> result{-1, -1};
    if (len == 0)
        return result;
    int i = 0, j = len;
    while (i < j) {
        int mid = i + (j - i) / 2;
        if (nums[mid] == target) {
            int low = mid - 1;
            while (low >= 0 && nums[low] == target) --low;
            result[0] = low + 1;

            int up = mid + 1;
            while (up < len && nums[up] == target) ++up;
            result[1] = up - 1;

            return result;
        }
        else if (nums[mid] < target)
            i = mid + 1;
        else
            j = mid;
    }
    return result;
}

int main() {
    vector<int> a{1, 3};
    for (auto i : searchRange(a, 1))
        cout << i << endl;
    return 0;
}
