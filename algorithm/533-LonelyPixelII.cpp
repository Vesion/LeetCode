#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

// Solution 1 : naive, O(n^4)
class Solution_1 {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty()) return 0;
        int m = picture.size(), n = picture[0].size();
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) if (picture[i][j] == 'B') ++row[i], ++col[j];
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B' && row[i] == N && col[j] == N) {
                    bool rule2 = true;
                    for (int k = 0; k < m; ++k) {
                        if (k != i && picture[k][j] == 'B') {
                            for (int l = 0; l < n; ++l) {
                                if (picture[k][l] != picture[i][l]) { rule2 = false; break; }
                            }
                            if (!rule2) break;
                        }
                    }
                    if (rule2) ++res;
                }
            }
        }
        return res;
    }
};


// Solution 2 : hash table, O(n^2) time, O(n^2) space
// https://discuss.leetcode.com/topic/81686/verbose-java-o-m-n-solution-hashmap
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        if (picture.empty()) return 0;
        int m = picture.size(), n = picture[0].size();
        vector<int> colB(n, 0);
        unordered_map<string, int> table;

        // count the rows which has N 'B's
        for (int i = 0; i < m; ++i) {
            string row;
            int rowB = 0;
            for (int j = 0; j < n; ++j) {
                row += picture[i][j];
                if (picture[i][j] == 'B') { ++rowB; ++colB[j]; }
            }
            if (rowB == N) table[row]++;
        }

        int res = 0;
        for (auto& p : table) {
            if (p.second == N) {
                string row = p.first;
                for (int j = 0; j < n; ++j) {
                    if (row[j] == 'B' && colB[j] == N) res += N;
                }
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
