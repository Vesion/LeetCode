#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

// https://leetcode.com/problems/range-module/discuss/108912/C%2B%2B-vector-O(n)-and-map-O(logn)-compare-two-solutions

// Solution 1 : vector, O(n) add and delete, O(logn) query
class RangeModule0 {
public:
    struct Range { int left, right; };
    vector<Range> ranges;

    void addRange(int left, int right) {
        int n = ranges.size();
        int i = 0;
        vector<Range> t;
        for (; i < n; ++i) {
            const Range& r = ranges[i];
            if (left > r.right) t.push_back(r);
            else if (right < r.left) break;
            else {
                left = min(left, r.left);
                right = max(right, r.right);
            }
        }
        t.push_back({left, right});
        for (; i < n; ++i) t.push_back(ranges[i]);
        t.swap(ranges);
    }

    bool queryRange(int left, int right) {
        int l = 0, r = ranges.size();
        while (l < r) {
            int mid = l + (r-l)/2;
            const Range& mr = ranges[mid];
            if (left >= mr.right) l = mid+1;
            else if (right <= mr.left) r = mid;
            else return left >= mr.left && right <= mr.right;
        }
        return false;
    }

    void removeRange(int left, int right) {
        int n = ranges.size();
        vector<Range> t;
        for (const Range& r : ranges) {
            if (left >= r.right || right <= r.left) t.push_back(r);
            else {
                if (left > r.left) t.push_back({r.left, left});
                if (right < r.right) t.push_back({right, r.right});
            }
        }
        t.swap(ranges);
    }
};


// Solution 2 : BST, O(klogn) add and delete (k is the number of overlapping ranges), O(logn) query
class RangeModule {
public:
    map<int,int> m;
    RangeModule() {}

    void addRange(int left, int right) {
        auto lit = m.upper_bound(left), rit = m.upper_bound(right);
        if (lit != m.begin()) {
            if (prev(lit)->second >= left) --lit;
        }
        if (lit != rit) {
            left = min(lit->first, left);
            right = max(prev(rit)->second, right);
            m.erase(lit, rit);
        }
        m[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = m.upper_bound(left);
        if (it == m.begin()) return false;
        return prev(it)->second >= right;
    }

    void removeRange(int left, int right) {
        auto lit = m.upper_bound(left), rit = m.upper_bound(right);
        if (lit != m.begin()) {
            if (prev(lit)->second >= left) --lit;
        }
        if (lit == rit) return;
        int l1 = min(lit->first, left), r1 = max(prev(rit)->second, right);
        m.erase(lit, rit);
        if (l1 < left) m[l1] = left;
        if (r1 > right) m[right] = r1;
    }
};


// Solution 3 : Segment Tree, O(logN) add and delete, O(logN) query, but here N are in (0, 10^9)


int main() {
  return 0;
}
