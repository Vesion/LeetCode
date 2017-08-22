#include <iostream>
#include <cstring>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M; 

    vector<vector<int>> A(N, vector<int>(2, 0));
    vector<vector<int>> B(N, vector<int>(2, 0));
    for (int i = 0; i < N; ++i) {
        cin >> A[i][1] >> B[i][1];

        int sum = B[i][1], bi = B[i][1];
        while (bi*1.07 + sum <= M) {
            bi *= 1.07;
            sum += bi;
            B[i].push_back(sum);
            A[i].push_back(A[i].back()+A[i][1]);
        }
    }
    
    vector<int> dp(M+1, 0);
    for (int k = 0; k < N; ++k) {
        for (int j = M; j >= 1; --j) {
            for (int i = 0; i < (int)B[k].size(); ++i) {
                if (j >= B[k][i]) dp[j] = max(dp[j], dp[j-B[k][i]]+A[k][i]);
            }
        }
    }

    cout << dp[M] << endl;
    return 0;
}
