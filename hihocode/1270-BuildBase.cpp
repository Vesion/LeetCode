#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

inline bool isValid(vector<int>& B) {
    for (int i = 0; i < B.size(); ++i)
        if (B[i] != 0) return true;
    return false;
}

int main() {
    ifstream cin("in.txt");
    int cases;
    cin >> cases;
    while (cases--) {
        int N, M, K, T;
        cin >> N >> M >> K >> T;
        vector<int> A(M), B(M);
        for (int i = 0; i < M; ++i) cin >> A[i];
        for (int i = 0; i < M; ++i) cin >> B[i];

        // solve
        bool solved = true;
        int result = 0;
        while (N--) {
            // check B
            if (!isValid(B)) {
                solved = false;
                break;
            }

            // dp, complete pack problem
            vector<int> dp(K+1, 0xff);
            dp[0] = 0;
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j <= K; ++j) {
                    int d = min(K, j+B[i]);
                    dp[d] = min(dp[d], dp[j]+A[i]);
                }
            }
            result += dp[K];
            
            // penalty
            for (int i = 0; i < M; ++i) B[i] /= T;
        }
        
        if (!solved) cout << "No Answer" << endl;
        else cout << result << endl;
    }
    return 0;
}
