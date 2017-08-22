#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : trivial, ignore 0s
class Solution_1 {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int l = A.size(), m = A[0].size(), n = B[0].size();
        vector<vector<int>> C(l, vector<int>(n, 0));
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < m; ++j) {
                if (A[i][j] == 0) continue;
                for (int k = 0; k < n; ++k) {
                    if (B[j][k] == 0) continue;
                    C[i][k] += A[i][j] * B[j][k];
                }
            }
        }
        return C;
    }
};


// Solution 2 : hash table
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int l = A.size(), m = A[0].size(), n = B[0].size();
        vector<vector<int>> C(l, vector<int>(n, 0));

        vector<vector<pair<int,int>>> sparseA(l);
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < m; ++j) {
                if (A[i][j] != 0) sparseA[i].emplace_back(j, A[i][j]);
            }
        }

        for (int i = 0; i < l; ++i) {
            for (auto& num : sparseA[i]) {
                for (int j = 0; j < n; ++j) {
                    if (B[num.first][j] != 0) C[i][j] += num.second * B[num.first][j];
                }
            }
        }
        return C;
    }
};


int main() {
    return 0;
}
