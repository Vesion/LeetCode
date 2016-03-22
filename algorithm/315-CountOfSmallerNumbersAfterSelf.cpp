#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Solution 1 : merge sort based, O(nlgn) time, O(n) space
// Similar to 'find inverted pairs' problem, these kinds of problems can be sold by merge sort.
// MergeSort based solution is a standard way to solve problems related to inverse numbers.
// https://leetcode.com/discuss/73509/nlogn-time-space-mergesort-solution-with-detail-explanation
void mergeCount(vector<int>& nums, int first, int last, vector<int>& indices, vector<int>& result) {
    if (first + 1 >= last) return;
    int mid = first + (last-first)/2;
    mergeCount(nums, first, mid, indices, result);
    mergeCount(nums, mid, last, indices, result);
    vector<int> tmp;
    tmp.reserve(last-first);
    int li = first, ri = mid; // two parts' iterators
    int count = 0; // count inverse numbers in second part
    while (li < mid || ri < last) {
        if ((ri == last) ||
            (li < mid && nums[indices[li]] <= nums[indices[ri]])) { // push element from first part, and set it's result
            tmp.push_back(indices[li]);
            result[indices[li]] += count;
            ++li;
        } else { // push element from second part, it must be smaller than some element in first part. so we increase count
            tmp.push_back(indices[ri]);
            ++count;
            ++ri;
        }
    }
    move(tmp.begin(), tmp.end(), indices.begin()+first); // use move rather than copy for better performance
}

vector<int> countSmaller(vector<int>& nums) {
    if (nums.empty()) return {};
    int n = nums.size();
    vector<int> result(n, 0); // to be returned
    vector<int> indices(n, 0); // tp record each element's position
    iota(indices.begin(), indices.end(), 0); // iota is similar to python's 'enumerate' function
    mergeCount(nums, 0, n, indices, result);
    return result;
}


// More great solutions are on discuss, let's implement them latter :)

// Solution 2 : Binary Search Tree


// Solution 3 : Binary Indexed Tree (Fenwick Tree)


// Solution 4 : Segment Tree


int main() {
    vector<int> nums = {5, 2, 6, 1};
    auto r = countSmaller(nums);
    for (auto i : r) cout << i << " "; cout << endl;
    return 0;
}
