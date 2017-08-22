#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<int> st;
    int n = s.size();
    vector<pair<int,int>> res;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') st.push(i);
        else {
            res.push_back({st.top(), i});
            st.pop();
        }
    }
    sort(res.begin(), res.end());
    for (auto& p : res) cout << p.first+1 << " " << p.second+1 << endl;
    return 0;
}
