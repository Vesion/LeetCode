#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


// Solution 1 : binary indexed tree.
class NumArray {
private:
    vector<int> nums;
    vector<int> sums;

public:
    NumArray(vector<int> &nums) {
        this->nums = nums;
        int n = nums.size();
        sums.resize(n+1, 0);
        for (int i = 0; i < n; ++i)
            add(i, nums[i]);
    }

    void add(int i, int val) {
        i++;
        while (i < (int)sums.size()) {
            sums[i] += val;
            i += (i & -i);
        }
    }

    int query(int i) {
        i++;
        int sum = 0;
        while (i > 0) {
            sum += sums[i];
            i -= (i & -i);
        }
        return sum;
    }

    void update(int i, int val) {
        add(i, val-nums[i]);
        nums[i] = val;
    }

    int sumRange(int i, int j) {
        return query(j) - query(i-1);
    }
};


// Solution 2 : segment tree.
class NumArray_st {
private:
    struct SegmentNode {
        int start, end;
        int sum;
        SegmentNode *left, *right;
        SegmentNode(int s, int e) : start(s), end(e), sum(0) {}
    };

    SegmentNode* root = NULL;

    SegmentNode* build(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        SegmentNode* node = new SegmentNode(start, end);
        if (start == end) node->sum = nums[start];
        else {
            int mid = start + (end-start)/2;
            node->left = build(nums, start, mid);
            node->right = build(nums, mid+1, end);
            node->sum = node->left->sum + node->right->sum;
        }
        return node;
    }

    void update(SegmentNode* root, int i, int val) {
        if (root->start == root->end) root->sum = val;
        else {
            int mid = root->start + (root->end-root->start)/2;
            if (i <= mid) update(root->left, i, val);
            else update(root->right, i, val);
            root->sum = root->left->sum + root->right->sum;
        }
    }

    int query(SegmentNode* root, int start, int end) {
        if (root->start == start && root->end == end)
            return root->sum;
        int mid = root->start + (root->end-root->start)/2;
        if (end <= mid) return query(root->left, start, end);
        if (start > mid) return query(root->right, start, end);
        return query(root->left, start, mid) + query(root->right, mid+1, end);
    }

public:
    NumArray_st(vector<int> &nums) {
        root = build(nums, 0, nums.size()-1);        
    }

    void update(int i, int val) {
        update(root, i, val);
    }

    int sumRange(int i, int j) {
        return query(root, i, j);
    }
};


int main() {
    vector<int> nums = {1, 3, 5};
    NumArray_st numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    numArray.update(1, 2);
    cout << numArray.sumRange(0, 2) << endl;
    return 0;
}
