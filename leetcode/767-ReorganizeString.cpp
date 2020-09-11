#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// Solution 1 : Heap, O(nlogn)
class Solution1 {
public:
    string reorganizeString(string S) {
        unordered_map<char,int> m;
        for (char c : S) m[c]++;

        priority_queue<pair<int,char>> pq;
        for (const auto& p : m) pq.push({p.second, p.first});

        string res;
        while (!pq.empty()) {
            auto p1 = pq.top(); pq.pop();
            if (res.empty() || res.back() != p1.second) {
                res += p1.second;
                --p1.first;
            }
            else if (pq.empty()) return "";
            else {
                auto p2 = pq.top(); pq.pop();
                res += p2.second;
                if (p2.first - 1 > 0) pq.push({p2.first-1, p2.second});
            }
            if (p1.first > 0) pq.push({p1.first, p1.second});
        }
        return res;
    }
};


// Solution 2 : Sort, O(n)
class Solution {
public:
    string reorganizeString(string S) {
        const int n = S.size();
        const int mid = (n-1)/2+1;  // 9->5, 10->5

        int m[26] = {0};
        for (char c : S) m[c-'a']++;

        vector<pair<int,char>> v;
        for (int i = 0; i < 26; ++i) {
            if (m[i] > mid) return "";
            if (m[i]) v.push_back({m[i], i+'a'});
        }
        sort(v.begin(), v.end(), greater<pair<int,char>>());

        string s;
        for (const auto& p : v) s += string(p.first, p.second);

        string res;
        for (int i = 0, j = mid; i < mid; ++i, ++j) {
            res += s[i];
            if (j < n) res += s[j];
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.reorganizeString("aabbccddddddd") << endl;
    return 0;
}
