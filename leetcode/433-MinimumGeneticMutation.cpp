#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
#include <unordered_map> 
#include <queue> 
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, bool> m;
        for (auto& b : bank) m.insert({b, false});

        if (start == end) return 0;
        if (start != end && !m.count(end)) return -1;

        queue<pair<string, int>> q;
        q.push({start, 0});
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            string cur = p.first;
            int level = p.second;

            if (cur == end) return level;

            for (int i = 0; i < (int)cur.size(); ++i) {
                string cur_copy = cur;
                for (char& c : string("ACTG")) {
                    if (cur_copy[i] != c) {
                        cur_copy[i] = c;
                        if (m.count(cur_copy) && m[cur_copy] == false) {
                            q.push({cur_copy, level+1});
                            m[cur_copy] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    cout << s.minMutation("AACCGGTT", "AAACGGTA", bank) << endl;
    return 0;
}
