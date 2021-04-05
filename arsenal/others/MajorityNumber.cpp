#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// The classical Majority Number Problem
// Given an array of integers and a number k, the majority number is the number that occurs more than 1/k of the size of the array.
//
// Solution : Boyer Moore Voting Algorithm


// Version 1 : The simplest, find the number occurs more than 1/2
int majorityNumber(vector<int>& nums) {
    int count = 1, result = 0;
    for (auto &num : nums) {
        if (num == result)
            ++count;
        else if (count == 0) {
            count = 1;
            result = num;
        }
        else --count;
    }
    return result;
}


// Version 2 : Find the number occurs more than 1/3
vector<int> majorityElement(vector<int>& nums) {
    int r1 = 0, c1 = 0, r2 = 1, c2 = 0;
    for (int& num : nums) {
        if (num == r1) ++c1;
        else if (num == r2) ++c2;
        else {
            if (c1 == 0) { r1 = num; c1 = 1; }
            else if (c2 == 0) { r2 = num; c2 = 1; }
            else { --c1; --c2; }
        }
    }
    c1 = c2 = 0;
    for (int& num : nums) {
        if (num == r1) ++c1;
        else if (num == r2) ++c2;
    }
    vector<int> res;
    if (c1 > (int)nums.size()/3) res.push_back(r1);
    if (c2 > (int)nums.size()/3) res.push_back(r2);
    return res;
}

// Version3 : Find numbers occurs more than 1/k
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        constexpr int k = 3;
        vector<int> c(k, 0), r(k);
        iota(r.begin(), r.end(), 0);  // to make r[i] unique
        for (int num : nums) {
            bool voted = false;
            for (int i = 0; i < k; ++i) {
                if (num == r[i] || c[i] == 0) {
                    ++c[i];
                    voted = true;
                    r[i] = num;  // for c[i] == 0
                    break;
                }
            }
            if (!voted) for (int i = 0; i < k; ++i) --c[i];
        }

        fill(c.begin(), c.end(), 0);
        unordered_set<int> res;
        for (int num : nums) {
            for (int i = 0; i < k; ++i) {
                if (num == r[i]) ++c[i];
                if (c[i] > nums.size()/k) res.insert(r[i]);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};


// Version 4 : Range majority query
// https://leetcode.com/problems/online-majority-element-in-subarray/
class MajorityChecker {
    const int kMax = 2e4+5;
    struct Node {
        int majority;  // majority number in a range
        int count;  // voting count, not total count in a range
    };
    int n;
    vector<Node> tree;
    vector<int> nums;
    vector<vector<int>> indice;

    // Boyer-Moore voting
    Node merge(const Node& a, const Node& b) {
        if (a.majority == b.majority) return {a.majority, a.count + b.count};
        if (a.count > b.count) return {a.majority, a.count - b.count};
        return {b.majority, b.count - a.count};
    }

    // build tree[i] with range [l, r]
    void build(int i, int l, int r) {
        if (l == r) {  // leaf node
            tree[i] = {nums[l-1], 1}; // remember range starts from index 1
            return;
        }
        int mid = l+(r-l)/2;
        build(i*2, l, mid);
        build(i*2+1, mid+1, r);
        // the push_up operation when build/update a segment tree
        tree[i] = merge(tree[i*2], tree[i*2+1]);
    }

    // for tree[i] with range [l, r], and a query [L, R],
    // return the majority number and its count
    Node query_majority(int i, int l, int r, int L, int R) {
        if (L > r || R < l) return {0, 0};
        if (L <= l && R >= r) return tree[i];
        int mid = l+(r-l)/2;
        Node a = query_majority(i*2, l, mid, L, R);
        Node b = query_majority(i*2+1, mid+1, r, L, R);
        return merge(a, b);
    }

public:
    MajorityChecker(vector<int>& arr) {
        n = arr.size();
        // usually 4*N is enough for building a segment tree
        tree.resize(kMax<<2);
        nums = arr;
        indice.resize(kMax);
        for (int i = 0; i < n; ++i) indice[arr[i]].push_back(i);
        build(1, 1, n);
    }

    int query(int left, int right, int threshold) {
        // find the majority number candidate
        int num = query_majority(1, 1, n, left+1, right+1).majority;
        if (num == 0) return -1;
        // although it's a majority number, we also have to check if its occurrences is >= threshold
        // that's why we need indice and binary search
        const auto& ni = indice[num];
        int l = lower_bound(ni.begin(), ni.end(), left)-ni.begin();
        int r = upper_bound(ni.begin(), ni.end(), right)-ni.begin();
        if (r-l >= threshold) return num;
        return -1;
    }
};


int main() {
    return 0;
}
