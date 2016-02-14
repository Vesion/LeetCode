#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Solution 1 : dfs-backtracking, O(n^2), TLE of course
// this solution is only for understading dfs, could not solve this problem in time limit
// and we did not care about '0', so it cannot work well in all cases
void dfs(int &result, string &path, string &s, int cur) {
    if (cur == s.size()) {
        ++result;
        cout << path << endl;
        return;
    }
    path += (s[cur] - '1' + 'A');
    dfs(result, path, s, cur+1);
    path.pop_back();

    if (cur < s.size()-1 && s[cur] - '1' < 2 && s[cur+1] - '1' < 6) {
        int k = (s[cur] - '0') * 10 + (s[cur+1] - '1');
        path += (k + 'A');
        dfs(result, path, s, cur+2);
        path.pop_back();
    }
}

int numDecodings_dfs(string s) {
    if (s.empty()) return 0;
    int result = 0;    
    string path; // not neccessarily, just for illustration
    dfs(result, path, s, 0);
    return result;
}


// Solution 2 : dp, O(n), similiar to 070-ClimbingStairs
// well behaved
int numDecodings_dp(string s) {
    int n = s.size();
    if (n == 0 || s[0] == '0') return 0;
    vector<int> dp(n+1, 1); // dp[0] is for dp[2]

    for (int i = 1; i < n; ++i) {
        if (s[i] == '0') { // if s[i] is '0', must be '*0'
            if (s[i-1] == '0' || s[i-1] - '1' > 1) // if s[i-1] is invalid return
                return 0;
            dp[i+1] = dp[i-1];
        }
        else {
            dp[i+1] = dp[i];
            if (s[i-1] != '0') { // as above, '0' must be suffix, cannot be prefix
                int k = (s[i-1] - '0') * 10 + (s[i] - '0');
                if (1 <= k && k <= 26)
                    dp[i+1] += dp[i-1];
            }
        }
    } 
    return dp[n];
}

// solution 2 simple version, not faster, but only O(1) space
int numDecodings_dp_simple(string s) {
    if (s.empty() || s[0] == '0') return 0;
    int prev = 0, cur = 1, result = 0;
    for (int i = 1; i <= s.size(); ++i) {
        if (s[i-1] == '0') // if s[i] is '0', it must be suffix '0', so dp[i-1]=0
            cur = 0;
        if (i < 2 || !(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))) // if s[i-1] is invalid, dp[i-2]=0
            prev = 0;
        result = prev + cur; // dp[i] = dp[i-1] + dp[i-2]
        prev = cur;
        cur = result;
    }
    return result;
}

int main() {
    //cout << numDecodings_dfs("123123") << endl; // wrong
    cout << numDecodings_dp("1101231") << endl;
    cout << numDecodings_dp_simple("1101231") << endl;
    return 0;
}
