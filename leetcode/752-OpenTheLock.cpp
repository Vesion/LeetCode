#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

// BFS
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        queue<string> q;
        q.push("0000"); dead.insert("0000");
        int res = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                string s = q.front(); q.pop();
                if (s == target) return res;
                for (int i = 0; i < 4; ++i) {
                    char c = s[i];
                    for (int d : {1,-1}) {
                        s[i] = (c-'0'+d+10)%10 + '0';
                        if (!dead.count(s)) {
                            q.push(s); dead.insert(s);
                        }
                    }
                    s[i] = c;
                }
            }
            ++res;
        }
        return -1;
    }
};

// Two-ends BFS, should have been faster than one-end, but unordered_set has notable overhead
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s1, s2, sd;
        s1.insert("0000");
        s2.insert(target);
        for (const string& d : deadends) sd.insert(d);
        if (sd.count("0000")) return -1;

        int step = 0;
        while (!s1.empty() && !s2.empty()) {
            auto& from = s1.size() >= s2.size() ? s1 : s2;
            auto& to = s1.size() < s2.size() ? s1 : s2;
            unordered_set<string> snew;
            for (const string& s : from) {
                if (to.count(s)) return step;
                string ns = s;
                for (int i = 0; i < 4; ++i) {
                    char od = ns[i];
                    for (int d = -1; d <= 1; d += 2) {
                        ns[i] = (od-'0'+10+d)%10 + '0';
                        if (!sd.count(ns)) {
                            snew.insert(ns);
                            sd.insert(ns);
                        }
                        ns[i] = od;
                    }
                }
            }
            from.swap(snew);
            ++step;
        }
        return -1;
    }
};


int main() {
}
