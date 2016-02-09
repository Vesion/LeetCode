#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

// tweak STL unique, use swapping to replace replacing
vector<int>::iterator myUnique(vector<int>::iterator first, vector<int>::iterator last) {
    if (first == last) return last;
    auto result = first;
    while (++first != last) {
        if (*result != *first)
            //*(++result) = *first; // here we do not replace ++result with first, but swap
            iter_swap(++result, first);
    }
    return ++result;
}

int removeDuplicates(vector<int>& nums) {
    vector<int>::iterator result = myUnique(nums.begin(), nums.end());
    sort(result, nums.end());
    result = myUnique(result, nums.end());
    sort(nums.begin(), result); // question ask for sorted result nums
    return (result - nums.begin());
}

// another good solution, and can be apply to occur times is 3, 4, ...
int removeDuplicates_good(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) return n;
    int result = 2;
    for (int i = 2; i < n; ++i) {
        if (nums[i] != nums[result-2])
            nums[result++] = nums[i];
    }
    return result;
}


int main() {
    vector<int> a{1, 1, 1, 1, 2, 3};
    //cout << removeDuplicates(a) << endl;
    cout << removeDuplicates_good(a) << endl;
    cout << endl;

    for (auto i : a)
        cout << i << " ";
    cout << endl; 
    return 0;
}

