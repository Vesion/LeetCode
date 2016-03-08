#include <iostream>
#include <vector>
using namespace std;

// Firstly, I use dp[i][j] to store the minimal 'initial' health when reach dungeon[i][j].
// But it turns out that I cannot write correct state transformation, so I realize its wrong with dp representation.

// actually, we should calculate from bottom-right to top-left
// dp[i][j] represents the minimal heath (not initial need health) when reach dungeon[i][j]
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
    dp[m][n-1] = dp[m-1][n] = 1;
    for (int i = m-1; i >= 0; --i) {
        for (int j = n-1; j >= 0; --j) {
            int need = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
            // if need<=0, it means that dungean[i][j] is positive, and is bigger than its down and right neighbors, so in dungeon[i][j] health is 1
            dp[i][j] = need > 0 ? need : 1;
        }
    }
    return dp[0][0];
}

// 为什么用dp表示初始血量不行，因为这样问题还存在后效性，即后面的房间的状态会影响前面的状态，从而无法得到递推关系。
// 反过来想，一开始可以确定的状态是什么，就是到达最后一个房间前所需要的最小血量，是max(1, 1-dungeon[m][n])，而且确定后不会改变了，从而知道好的状态应该是当前房间的所需最小血量，并且要从后往前推，推到第一个房间时，就是问题所要求的minimal initial health了。所以关键还是要找对状态表示。

int main() {
    vector<vector<int>> dungeon = {
        {1, -3, 3},
        {0, -2, 0},
        {-3, -3, -3}};
    cout << calculateMinimumHP(dungeon) << endl;
    return 0;
}
