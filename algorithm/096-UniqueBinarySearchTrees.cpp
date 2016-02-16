#include <iostream>
#include <vector>
using namespace std;

// classical dp problem
// 对于由1,2,...,n构成的二叉搜索树有如下性质：
// 当根节点是i时，左子树由1,..,i-1组成，右子树由i+1,...,n组成，且左子树的个数乘以右子树的个数等于以i为根的所有树的个数
// dp[i]表示1,...,i组成的二叉搜索树的个数，则dp[i]=sum{dp[k-1] * dp[i-k], k=1,...,i}
//
int numTrees(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int k = 1; k <= i; ++k)
            dp[i] += dp[k-1] * dp[i-k];
    }
    return dp[n];
}

int main() {
    cout << numTrees(3) << endl;
    return 0;
}
