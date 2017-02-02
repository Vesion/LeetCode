#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// Solution 1 : heap, O(nlogn)
class Solution_1 {
public:
    string frequencySort(string s) {
        vector<int> m(128, 0);
        for (char c : s) m[c]++;
        priority_queue<pair<int, char>> q;
        for (int i = 0; i < 128; ++i)
            if (m[i]) q.push({m[i], i});
        string res;
        while (!q.empty()) {
            int t = q.top().first;
            char c = q.top().second;
            q.pop();
            res += string(t, c);
        }
        return res;
    }
};


// Solution 2 : sort with frequency, O(nlogn)
class Solution_2 {
public:
    string frequencySort(string s) {
        vector<int> m(128, 0);
        for (char c : s) m[c]++;
        sort(s.begin(), s.end(), 
            [&m](const char& c1, const char& c2) {
                if (m[c1] == m[c2]) return c1 < c2;
                return m[c1] > m[c2]; });
        return s;
    }
};


// Solution 3 : bucket sort, O(n)
class Solution {
public:
    string frequencySort(string s) {
        vector<int> m(128, 0);
        for (char& c : s) m[c]++;
        
        int n = s.size();
        vector<string> buckets(n+1);
        for (int c = 0; c < 128; ++c) buckets[m[c]] += string(m[c], (char)c);
        
        string res;
        for (int i = n; i >= 0; --i) res += buckets[i];
        return res;
    }
};


int main() {
    Solution s;
    cout << s.frequencySort("") << endl;
    return 0;
}
