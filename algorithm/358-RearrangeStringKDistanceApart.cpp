#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <queue> 
using namespace std;

class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k == 0) return str;

        unordered_map<char, int> m;
        for (char c : str) m[c]++; // count each letter's occurrences
        priority_queue<pair<int, char>> q; // max-heap
        for (auto& p : m) q.push({p.second, p.first});

        string res;
        while (!q.empty()) { // in each turn, try to pick k different characters, according to their remaining numbers
            int ck = k;
            vector<pair<int, char>> cache; // cache those characters have been pick in this turn
            while (ck--) {
                if (q.empty()) { // if there is no candidates
                    if (cache.empty()) break; // and no cache, it is over
                    else return ""; // else we cannot arrange
                }
                auto p = q.top(); q.pop();
                res += p.second;
                if (--p.first > 0) cache.push_back(p);
            }
            for (auto& p : cache) q.push(p); // put cache back
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.rearrangeString("aabbcc", 1) <<endl;
    return 0;
}

