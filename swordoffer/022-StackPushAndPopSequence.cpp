#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// Problem:
//      Given an array a as stack pushing sequence, and an array b, judge if b may be valid stack poping sequence.

class Solution {
public:
    bool IsPopOrder(vector<int> a,vector<int> b) {
        stack<int> st;
        int n = a.size();
        int i = 0, j = 0;
        while (i < n) {
            if (a[i] == b[j]) ++j;
            else st.push(a[i]);
            ++i;
        }
        while (!st.empty()) {
            if (b[j++] == st.top()) st.pop();
            else return false;
        }
        return j == n;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {4, 5, 3, 2, 1};
    cout << s.IsPopOrder(a, b) << endl;
    return 0;
}
