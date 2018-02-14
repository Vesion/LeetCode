#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// Solution 1 : Heap, O(nlogn)
class Solution_1 {
public:
  string reorganizeString(string s) {
    int cnt[26] = {0};
    for (char c : s) cnt[c-'a']++;
    priority_queue<pair<int,char>> pq;
    for (int i = 0; i < 26; ++i) if (cnt[i]) pq.push({cnt[i], i+'a'});
    string res;
    while (!pq.empty()) {
      if (pq.size() == 1) {
        auto t = pq.top(); pq.pop();
        if (t.first != 1) return "";
        res += t.second;
      } else {
        auto a = pq.top(); pq.pop();
        res += a.second; --a.first;
        auto b = pq.top(); pq.pop();
        res += b.second; --b.first;
        if (a.first) pq.push(a);
        if (b.first) pq.push(b);
      }
    }
    return res;
  }
};


// Solution 2 : Sort, O(n)
class Solution {
public:
  string reorganizeString(string s) {
    int n = s.size(), cnt[26] = {0};
    for (char c : s) cnt[c-'a']++;
    vector<pair<int,char>> v;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] > (n+1)/2) return "";
      v.push_back({cnt[i], i+'a'});
    }
    sort(v.begin(), v.end(), greater<pair<int,char>>());
    string ss;
    for (auto& p : v) ss += string(p.first, p.second);
    string res;
    for (int i = 0, j = (n-1)/2+1; i <= (n-1)/2; ++i, ++j) {
      res += ss[i];
      if (j < n) res += ss[j];
    }
    return res;
  }
};


int main() {
  Solution s;
  cout << s.reorganizeString("aabbccddddddd") << endl;
  return 0;
}
