#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// index starts from 0
void makeset(vector<int>& root, vector<int>& rank) {
    for (int i = 0; i < (int)root.size(); ++i) {
        root[i] = i;
        rank[i] = 0;
    }
}

// with path compression
int findroot(vector<int>& root, vector<int>& rank, int x) {
    if (x != root[x])
        root[x] = findroot(root, rank, root[x]);
    return root[x];
}

// with rank
void unionset(vector<int>& root, vector<int>& rank, int x, int y) {
    int rx = findroot(root, rank, x);
    int ry = findroot(root, rank, y);
    if (rx == ry) return;
    if (rank[rx] > rank[ry])
        root[ry] = rx;
    else {
        root[rx] = ry;
        if (rank[rx] == rank[ry])
            ++rank[ry];
    }
}


int getSetsNum(vector<int>& root) {
    int num = 0;
    for (int i = 0; i < (int)root.size(); ++i)
        if (root[i] == i) ++num;
    return num;
}

int main() {
    vector<int> nums = {1, 4, 5, 3, 2, 0, 6};
    int n = nums.size();
    vector<int> root(n), rank(n);

    makeset(root, rank);
    for (int i = 0; i < n; ++i)
        unionset(root, rank, i, nums[i]);
    
    for (auto i : root) cout << i << " "; cout << endl;
    for (auto i : rank) cout << i << " "; cout << endl;
    cout << getSetsNum(root) << endl;
}
