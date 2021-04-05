#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        int d[26];
        for (int i = 0; i < 26; ++i) d[order[i]-'a'] = i;
        for (int i = 0; i < n-1; ++i) {
            const string& cur = words[i];
            const string& next = words[i+1];
            for (int k = 0; k < cur.size(); ++k) {
                if (k == next.size()) return false;
                if (d[cur[k]-'a'] < d[next[k]-'a']) break;
                if (d[cur[k]-'a'] > d[next[k]-'a']) return false;
            }
        }
        return true;
    }
};


int main() {

}