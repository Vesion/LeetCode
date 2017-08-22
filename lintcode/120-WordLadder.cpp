#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
#include <map> 
#include <queue> 
using namespace std;

// Solution 1 : dfs backtracking, TLE!
class Solution_1 {
public:
    int result = INT_MAX;
    map<string, bool> m;

    void dfs(string start, string end, unordered_set<string>& dict, int steps) {
        if (start == end) {
            result = min(result, steps);
            return;
        }
        for (int i = 0; i < (int)start.size(); ++i) {
            for (int j = 0; j < 26; ++j) {
                char old = start[i];
                start[i] = 'a'+j;
                if (!m[start] && (dict.count(start) || start == end)) {
                    m[start] = true;
                    dfs(start, end, dict, steps+1);
                    m[start] = false;
                }
                start[i] = old;
            }
        }
    }

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        dfs(start, end, dict, 1);
        return result == INT_MAX ? 0 : result;
    }
};



// Solution 2 : bfs
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<pair<string, int>> q;
        q.push({start, 1});
        dict.insert(end);

        while (!q.empty()) {
            auto p = q.front(); q.pop();
            string s = p.first;

            if (s == end) return p.second;

            for (int i = 0; i < (int)s.size(); ++i) {
                string temp = s;
                for (char c = 'a'; c <= 'z'; ++c) {
                    temp[i] = c;
                    auto it = dict.find(temp);
                    if (it != dict.end() && temp != s) {
                        q.push({temp, p.second+1});
                        dict.erase(it); // in case of cycle
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    unordered_set<string> dict = {"hot","dot","dog","lot","log"};
    cout << s.ladderLength("hit", "cog", dict) <<endl;
    return 0;
}
