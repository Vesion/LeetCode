#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// use STL next_permutation
void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
}

// implement next_permutation
// dictionary order
void next_permutation(vector<int>::iterator first, vector<int>::iterator last) {
    if (first == last || first == last - 1)
        return;

    auto i = last - 1;

    while (true) {
        vector<int>::iterator i1, i2;
        i1 = i;
        if (*--i < *i1) { // from right to left, find the first element i, smaller than its right adjacent one i1
            i2 = last;
            while (*i >= *--i2) ; // from right to i, find the first element i2, greater than i
            iter_swap(i, i2); // swap i and i2
            reverse(i1, last); // reverse from i1 to right
            return;
        }
        if (i == first) { // if i is the left first, means that this permutation turn is over
            reverse(first, last);
            return;
        }
    }
}

int main() {
    vector<int> nums{3, 2, 1};
    nextPermutation(nums);
    for (auto i : nums) {
        cout << i << endl;
    }
    return 0;
}
