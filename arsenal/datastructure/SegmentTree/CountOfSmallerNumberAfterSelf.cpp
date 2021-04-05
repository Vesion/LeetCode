#include <iostream>
#include <vector>
#include <numeric>
#include <set> 
#include <map> 
using namespace std;

// Solution 1 : merge sort based, O(nlgn) time, O(n) space
// Similar to 'find inverted pairs' problem, these kinds of problems can be sold by merge sort.
// MergeSort based solution is a standard way to solve problems related to inverse numbers.
// https://leetcode.com/discuss/73509/nlogn-time-space-mergesort-solution-with-detail-explanation
class Solution_MergeSort {
public:
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
};


// Solution 2 : Binary Search Tree


// Solution 3 : Binary Indexed Tree (Fenwick Tree)
class BinaryIndexedTree {
private:
    vector<int> sums;

public:
    BinaryIndexedTree(int n) {
        sums.resize(n+1, 0);
    }

    void update(int id, int value) {
        while (id < (int)sums.size()) {
            sums[id] += value;
            id += (id & -id);
        }
    }

    int query(int id) {
        int sum = 0;
        while (id > 0) {
            sum += sums[id];
            id -= (id & -id);
        }
        return sum;
    }
};

class Solution_BIT {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return {};
        set<int> sa(nums.begin(), nums.end());        
        map<int, int> ma;
        int i = 1;
        for (auto it = sa.begin(); it != sa.end(); ++it)
            ma.insert({*it, i++});
        BinaryIndexedTree bit(ma.size());
        vector<int> result;
        for (int i = (int)nums.size()-1; i >= 0; --i) {
            result.push_back(bit.query(ma[nums[i]]));
            bit.update(ma[nums[i]]+1, 1);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


// Solution 4 : Segment Tree
struct SegmentNode {
    int start, end, mid;
    int count = 0;
    SegmentNode *left, *right;
    SegmentNode(int s, int e, int m) : start(s), end(e), mid(m), left(NULL), right(NULL) {}
};

class SegmentTree {
private:
    SegmentNode* root;

    SegmentNode* build(int start, int end) {
        if (start >= end) return NULL;
        if (start+1 == end) {
            return new SegmentNode(start, end, start);
        }
        SegmentNode* root = new SegmentNode(start, end, (start+end)/2);
        root->left = build(start, root->mid);
        root->right = build(root->mid, end);
        return root;
    }

    void modify(SegmentNode* root, int index, int value) {
        if (!root || index < root->start || index >= root->end) return;
        if (index == root->start && index == root->end-1) {
            root->count += value;
            return;
        }
        if (index < root->mid) modify(root->left, index, value);
        else modify(root->right, index, value);
        root->count = root->left->count + root->right->count;
    }

    int query(SegmentNode* root, int start, int end) {
        if (!root || end <= root->start || start >= root->end) return 0;
        if (start <= root->start && end >= root->end) return root->count;
        if (end <= root->mid) return query(root->left, start, end);
        else if (start >= root->mid) return query(root->right, start, end);
        else return query(root->left, start, root->mid) + query(root->right, root->mid, end);
    }

public:
    SegmentTree(int size) {
        this->root = build(0, size);
    }

    void modify(int index, int value) {
        modify(root, index, value);
    }

    int query(int start, int end) {
        return query(root, start, end);
    }
};

class Solution_SegmentTree {
public:
    vector<int> countSmaller(vector<int> &nums) {
        if (nums.empty()) return {};
        set<int> sa(nums.begin(), nums.end());        
        map<int, int> ma;
        int i = 1;
        for (auto it = sa.begin(); it != sa.end(); ++it)
            ma.insert({*it, i++});
        SegmentTree st(ma.size()+10);
        vector<int> result;
        for (int i = (int)nums.size()-1; i >= 0; --i) {
            st.modify(ma[nums[i]], 1);
            result.push_back(st.query(0, ma[nums[i]]));
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


// test
int main() {
    vector<int> nums = {2, 4, 56, 2, 5, 9};
    Solution_MergeSort s1;
    auto r = s1.countSmaller(nums);
    for (auto i : r) cout << i << " "; cout << endl;

    Solution_SegmentTree s2;
    r = s2.countSmaller(nums);
    for (auto i : r) cout << i << " "; cout << endl;

    Solution_BIT s3;
    r = s3.countSmaller(nums);
    for (auto i : r) cout << i << " "; cout << endl;
    return 0;
}
