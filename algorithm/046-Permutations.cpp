#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

// same with STL next_permutation
bool xx_next_permutation(vector<int>::iterator first, vector<int>::iterator last) {
    if (first == last || first == last -1) {
        return false;
    }
    auto i = last - 1;
    for (;;) {
        auto i1 = i;
        if (*--i < *i1) {
            auto i2 = last;
            while (*i >= *--i2);
            iter_swap(i, i2);
            reverse(i1, last);
            return true;
        }
        if (i == first) {
            reverse(first, last);
            return false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.size() == 0) {
        return result;
    }
    sort(nums.begin(), nums.end());
    result.push_back(nums);
    while (next_permutation(nums.begin(), nums.end())) {
        result.push_back(nums);
    }
    return result;
}

int main() {
    vector<int> a = {1, 1, 2};
    auto result = permute(a);
    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
