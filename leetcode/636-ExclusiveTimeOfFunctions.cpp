#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        stack<pair<int,int>> st;
        for (const string& log : logs) {
            auto [i, start, t] = parse(log);
            if (start) {
                if (!st.empty()) res[st.top().first] += t-st.top().second;
                st.push({i, t});
            } else {
                int start_t = st.top().second;
                st.pop();
                res[i] += t-start_t+1;
                if (!st.empty()) st.top().second = t+1;
            }
        }
        return res;
    }

    tuple<int,bool,int> parse(const string& log) {
        int i; bool start; int t;
        int k = 0;
        istringstream ins(log);
        string token;
        while (getline(ins, token, ':')) {
            if (k == 0) i = stoi(token);
            else if (k == 1) start = token[0] == 's';
            else t = stoi(token);
            ++k;
        }
        return {i, start, t};
    }
};


int main() {
    Solution s;
    vector<string> l = { "0:start:0","1:start:2","1:end:5","0:end:6" };
    auto r = s.exclusiveTime(2, l);
    for (auto& e : r) cout << e << " "; cout << endl;
    return 0;
}
