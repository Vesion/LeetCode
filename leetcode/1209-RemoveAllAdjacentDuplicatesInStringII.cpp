#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;


// stack
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;
        for (char c : s) {
            if (st.empty() || st.back().first != c) {
                st.push_back({c, 1});
            } else if (++st.back().second == k) {
                st.pop_back();
            }
        }
        string res;
        for (const auto& p : st) res.append(p.second, p.first);
        return res;
    }
};


int main() {

}