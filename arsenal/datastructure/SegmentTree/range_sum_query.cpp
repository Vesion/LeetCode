#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Segment Tree, a type of interval tree wich takes a good advantage of binary search.
//      leaf nodes are original data (nums), other nodes are all intervals which store information(sum/min/max) of its childs
//
// Common methods:
//      build() : build/construct a segment tree, O(n)
//      query(l, r) : query information of [l, r] in nums, O(logn)
//      update(p, v) : update a single position p in nums, change it to v (or add v to it), O(logn)
//      update(l, r, v) : update an interval [l, r] in nums, here we need 'lazy' flag, O(logn)
//

const int MAX = 100; // range of input data

int nums[MAX]; // the input data
int sums[MAX*4]; // st tree, 4 * sizeof input data
int lazy[MAX*4]; // for updating interval

// update parent node with child nodes
void push_up(int i) {
    sums[i] = sums[i*2] + sums[i*2+1];
}

// push lazy flag down to childs, update childs' information, and erase parent's lazy flag
void push_down(int i, int l, int r) {
    if (lazy[i]) {
        lazy[i*2] += lazy[i];
        lazy[i*2+1] += lazy[i];
        int mid = l + (r-l)/2;
        sums[i*2] += lazy[i] * (mid-l+1);
        sums[i*2+1] += lazy[i] * (r-mid);
        lazy[i] = 0;
    }
}

// build the tree
void build(int i, int l, int r) {
    if (l == r) {
        sums[i] = nums[l];
        return;
    }
    int mid = l + (r-l)/2;
    build(i*2, l, mid);
    build(i*2+1, mid+1, r);
    push_up(i);
}


// update single point, add it to val
void update(int i, int l, int r, int pos, int val) {
    if (l == r) {
        sums[i] += val;
        return;
    }
    int mid = l + (r-l)/2;
    if (pos <= mid) update(i*2, l, mid, pos, val);
    else update(i*2+1, mid+1, r, pos, val);
    push_up(i);
}


// update interval [L, R], add each element in it to val
void update(int i, int l, int r, int L, int R, int val) {
    if (L <= l && r <= R) {
        sums[i] += (r-l+1)*val;
        lazy[i] += val;
        return;
    }
    push_down(i, l, r); // push down lazy if has flagged this interval before
    int mid = l + (r-l)/2;
    if (L <= mid) update(i*2, l, mid, L, R, val);
    if (R > mid) update(i*2+1, mid+1, r, L, R, val);
    push_up(i);
}


// query the interval [L, R]
int query(int i, int l, int r, int L, int R) {
    if (L <= l && r <= R)
        return sums[i];
    push_down(i, l, r); // push down lazy if has flagged this interval before
    int result = 0;;
    int mid = l + (r-l)/2;
    if (L <= mid) result += query(i*2, l, mid, L, R);
    if (R > mid) result += query(i*2+1, mid+1, r, L, R);
    return result;
}


int main() {
    int n = 10;
    for (int i = 1; i <= n; ++i) { 
        nums[i] = i;
    }
    build(1, 1, n);

    update(1, 1, n, 10, 10);
    cout << query(1, 1, n, 5, 5) << endl;;
    update(1, 1, n, 3, 7, 1);
    cout << query(1, 1, n, 1, 10) << endl;;
    return 0;
}
