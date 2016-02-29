#include <iostream>
#include <vector>
using namespace std;

// a hard greedy problem
// refer to https://leetcode.com/discuss/43581/solutions-given-explanation-time-with-space-other-with-space

// Solution 1 : two scans, O(2*n)time, O(n) space
// 第一步，从左往右扫描，如果自己的rating大于左边邻居的（右边大于左边），那自己的candies就是左边邻居的candies+1，否则就为1。完成这一遍扫描后，左邻居条件就满足了。
// 第二步，从右往左扫描，如果自己的rating大于右边邻居的（左边大于右边），那自己的candies就是右边邻居的candies+1，否则就为1。完成这一遍扫描后，右邻居条件就满足了。
// 第三步，candies去以上两者中的最大值，这就同时满足了左右邻居条件。
// 其中第三步和第二步可以合在一起写。
int candy_twoscans(vector<int>& ratings) {
    int n = ratings.size();
    if (n == 0) return 0;
    if (n == 1) return 1;
    vector<int> candies(n, 1);

    for (int i = 1; i < n; ++i)
        candies[i] = (ratings[i] > ratings[i-1] ? candies[i-1]+1 : 1);
    
    int total = candies[n-1];
    for (int i = n-2; i >= 0; --i) {
        if (ratings[i] > ratings[i+1])
            candies[i] = max(candies[i], candies[i+1]+1);
        total += candies[i];
    }
    return total;
}


// Solution 2 : one scan, improve solution 1, faster, O(n) time, O(1) space
// To be implemented
//


// Solution 3 : recursive with memo, skillful but slower than above
int solve(vector<int>& ratings, vector<int>& f, int i) {
    if (f[i] == 0) {
        f[i] = 1;
        if (i > 0 && ratings[i] > ratings[i-1])
            f[i] = max(f[i], solve(ratings, f, i-1) + 1);
        if (i < ratings.size()-1 && ratings[i] > ratings[i+1])
            f[i] = max(f[i], solve(ratings, f, i+1) + 1);
    }
    return f[i];
}

int candy_re(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> f(n, 0);
    int total = 0;
    for (int i = 0; i < n; ++i)
        total += solve(ratings, f, i);
    return total;
}

int main() {
    vector<int> ratings = {3, 4, 1, 10, 1};
    cout << candy_twoscans(ratings) << endl;
    return 0;
}
