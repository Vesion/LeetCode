#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        if (arr.size() < 2) return 0;
        // dedup, allow at most 2 consecutive equal numbers
        int n = 2;
        for (int i = 2; i < arr.size(); ++i) {
            if (arr[i] != arr[i-2] || arr[i] != arr[i-1]) arr[n++] = arr[i];
        }
        arr.resize(n);

        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; ++i) m[arr[i]].push_back(i);

        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0); vis[0] = true;
        int res = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int i = q.front(); q.pop();
                if (i == n-1) return res;
                auto& next = m[arr[i]];
                next.push_back(i-1);
                next.push_back(i+1);
                for (int ni : next) {
                    if (ni < 0 || ni >= n || vis[ni]) continue;
                    q.push(ni);
                    vis[ni] = true;
                }
            }
            ++res;
        }
        return -1;
    }
};


int main() {
    return 0;
}
