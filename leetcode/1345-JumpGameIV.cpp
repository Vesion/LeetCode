#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        if (arr.size() < 2) return 0;
        // dedup to speedup
        int n = 2;
        for (int i = 2; i < arr.size(); ++i) {
            if (arr[i] != arr[i-2] || arr[i] != arr[i-1]) arr[n++] = arr[i];
        }
        arr.resize(n);

        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; ++i) m[arr[i]].push_back(i);
        vector<bool> v(n, 0);

        vector<int> s; s.push_back(0); v[0] = true;
        int res = 0;
        while (!s.empty()) {
            vector<int> ns;
            for (const int i : s) {
                if (i == n-1) return res;
                auto& nis = m[arr[i]];
                nis.push_back(i+1); nis.push_back(i-1);
                for (const int ni : nis) {
                    if (ni >= 0 && ni < n && !v[ni]) {
                        ns.push_back(ni);
                        v[ni] = true;
                    }
                }
                nis.clear();  // to avoid duplicate states, speedup
            }
            s.swap(ns);
            ++res;
        }
        return -1;
    }
};


int main() {
    return 0;
}
