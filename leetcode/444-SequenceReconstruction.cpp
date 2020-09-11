#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;


// Solution 1 : build graph and topological sort
class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        const int n = org.size();
        vector<vector<int>> g(n+1);
        vector<int> ins(n+1, -1);
        for (const auto& seq : seqs) {
            for (int i = 0; i < seq.size(); ++i) {
                if (seq[i] < 1 || seq[i] > n) return false;
                ins[seq[i]] = 0;
                if (i > 0) g[seq[i-1]].push_back(seq[i]);
            }
        }
        for (int i = 1; i <= n; ++i) for (int j : g[i]) ins[j]++;

        queue<int> q;
        for (int i = 1; i <= n; ++i) if (ins[i] == 0) q.push(i);
        int i = 0;
        while (!q.empty()) {
            const int t = q.front();
            q.pop();
            if (!q.empty()|| i >= n || t != org[i++]) return false;
            for (int nt : g[t]) if (--ins[nt] == 0) q.push(nt);
        }
        return i == n;
    }
};

// Solution 2 : just check if every two adjacent elements of org also appears adjacently in the seqs
// https://discuss.leetcode.com/topic/65961/simple-solution-one-pass-using-only-array-c-92ms-java-16ms
class Solution_2 {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if(seqs.empty()) return false;
        vector<int> pos(org.size()+1);
        for(int i=0;i<org.size();++i) pos[org[i]] = i;

        vector<char> flags(org.size()+1,0);
        int toMatch = org.size()-1;
        for(const auto& v : seqs) {
            for(int i=0;i<v.size();++i) {
                if(v[i] <=0 || v[i] >org.size())return false;
                if(i==0)continue;
                int x = v[i-1], y = v[i];
                if(pos[x] >= pos[y]) return false;
                if(flags[x] == 0 && pos[x]+1 == pos[y]) flags[x] = 1, --toMatch;
            }
        }
        return toMatch == 0;
    }
};


int main() {
    Solution s;
    vector<int> org = {1, 2, 3, 4};
    vector<vector<int>> seqs = {{1,3}, {2,4}, {1,2},{2,3},{3,4} };
    cout << s.sequenceReconstruction(org, seqs) << endl;
    return 0;
}
