#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// solution 1 : counting sort, two-pass O(2*n)
void sortColors_count(vector<int>& nums) {
    int s[3] = {0};
    for (auto i : nums)
        s[i]++;
    int index = 0;
    for (int i = 0; i < 3; ) {
        if (s[i] > 0)
            nums[index++] = i;
        if (--s[i] <= 0)
            ++i;
    }
}


// solution 2 : two pointers, one-pass O(1*n)
void sortColors(vector<int>& nums) {
    int ri = 0, bi = nums.size()-1;
    for (int i = 0; i <= bi; ) {
        if (nums[i] == 0) {
            swap(nums[ri], nums[i]);
            i = ri + 1;
            ++ri;
        }
        else if (nums[i] == 2) {
            swap(nums[bi--], nums[i]);
        }
        else {
            ++i;
        }
    }
}

// solution 3 : refer to partition in quicksort, partition 0, then 1
//
//

int main() {
    //vector<int> nums = {2, 2, 1, 0, 0, 1, 1, 2, 0, 1};
    //sortColors(nums);
    vector<int> nums = {2, 1, 0};
    sortColors_count(nums);
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
    return 0;
}
