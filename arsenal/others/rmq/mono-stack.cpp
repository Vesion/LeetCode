#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// range minimum query

vector<int> rmq(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size(), m = queries.size();
    vector<int> qid(m); iota(qid.begin(), qid.end(), 0);
    sort(qid.begin(), qid.end(), [&queries](int i, int j) {
        if (queries[i][1] == queries[j][1]) return queries[i][0] < queries[j][0];
        return queries[i][1] < queries[j][1];
    });
    vector<int> st;
    int j = 0;
    vector<int> res(m);
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.back()] >= nums[i]) st.pop_back();
        st.push_back(i);
        while (j < m && i == queries[qid[j]][1]) {
            auto it = lower_bound(st.begin(), st.end(), queries[qid[j]][0]);
            res[qid[j]] = nums[*it];
            ++j;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {10, 10, 1, 2, 3, 4, 5, 6, 7};
    vector<vector<int>> queries = {
        {0, 1}, {2, 3}, {0, 6}, {1, 7}
    };
    auto res = rmq(nums, queries);
    for (int r : res) cout << r << " "; cout << endl;
    return 0;
}