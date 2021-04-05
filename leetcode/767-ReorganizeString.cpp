#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// similar to 621-TaskScheduler

// Solution 1 : Heap, O(nlogn)
class Solution {
public:
    string reorganizeString(string S) {
        int m[26] = {};
        for (char c : S) ++m[c-'a'];
        priority_queue<pair<int,char>> pq;
        for (int i = 0; i < 26; ++i) {
            if (m[i]) pq.push({m[i], 'a'+i});
        }

        string res;
        while (!pq.empty()) {
            auto [t, c] = pq.top(); pq.pop();
            if (res.empty() || res.back() != c) {
                res += c;
                --t;
            } else if (pq.empty()) {
                return "";
            } else {
                auto [t1, c1] = pq.top(); pq.pop();
                res += c1;
                if (t1 > 1) pq.push({t1-1, c1});
            }
            if (t > 0) pq.push({t, c});
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
