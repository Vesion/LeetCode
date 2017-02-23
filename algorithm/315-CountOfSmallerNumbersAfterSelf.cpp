#include <iostream>
#include <vector>
#include <numeric>
#include <set> 
#include <map> 
using namespace std;

// Solution 1 : merge sort based, O(nlgn) time, O(n) space
class Solution_1 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0), index(n, 0);
        iota(index.begin(), index.end(), 0);
        mergeSort(nums, 0, n, index, res);
        return res;
    }
    
    void mergeSort(vector<int>& nums, int first, int last, vector<int>& index, vector<int>& res) {
        if (first+1 >= last) return;
        int mid = first + (last-first)/2;
        mergeSort(nums, first, mid, index, res); 
        mergeSort(nums, mid, last, index, res);
        vector<int> cache(last-first);
        int j = mid, r = 0;
        int count = 0;
        for (int i = first; i < mid; ++i) {
            while (j < last && nums[index[i]] > nums[index[j]]) {
                ++count;
                cache[r++] = index[j++];
            }
            cache[r++] = index[i];
            res[index[i]] += count;
        }
        move(cache.begin(), cache.begin()+r, index.begin()+first);
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

class Solution_3 {
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

class Solution_4 {
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
    Solution_1 s1;
    auto r = s1.countSmaller(nums);
    for (auto i : r) cout << i << " "; cout << endl;

    Solution_3 s3;
    r = s3.countSmaller(nums);
    for (auto i : r) cout << i << " "; cout << endl;

    Solution_4 s4;
    r = s4.countSmaller(nums);
    for (auto i : r) cout << i << " "; cout << endl;
    return 0;
}
