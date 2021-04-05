#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// [0,1,0,0,0] -> [-1, 1, -3]
class SparseVector {
public:
    vector<int> m;
    SparseVector(vector<int> &nums) {
        int c = 0;
        for (int num : nums) {
            if (num) {
                if (c) {
                    m.push_back(-c);
                    c = 0;
                }
                m.push_back(num);
            } else ++c;
        }
        if (c) m.push_back(-c);
    }

    int dotProduct(SparseVector& vec) {
        vector<int> lm = m;
        vector<int> rm = vec.m;
        int res = 0;
        int i = 0, j = 0;
        while (i < lm.size() && j < rm.size()) {
            if (lm[i] < 0) {
                int t = -lm[i++];
                while (t) {
                    if (rm[j] > 0) --t, ++j;
                    else if (-rm[j] > t) { rm[j] += t; t = 0; }
                    else t += rm[j++];
                }
            } else if (rm[j] < 0) {
                int t = -rm[j++];
                while (t) {
                    if (lm[i] > 0) --t, ++i;
                    else if (-lm[i] > t) { lm[i] += t; t = 0; }
                    else t += lm[i++];
                }
            } else {
                res += lm[i++] * rm[j++];
            }
        }
        return res;
    }
};

// [0,1,0,0,2,0,0] -> [{1,1}, {4,2}]
class SparseVector1 {
public:
    vector<pair<int,int>> m;
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) m.push_back({i, nums[i]});
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for (int i = 0, j = 0; i < m.size() && j < vec.m.size(); ) {
            if (m[i].first < vec.m[j].first) ++i;
            else if (m[i].first > vec.m[j].first) ++j;
            else res += m[i++].second * vec.m[j++].second;
        }
        return res;
    }
};

int main() {

}