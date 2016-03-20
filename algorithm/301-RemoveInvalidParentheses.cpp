#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

// Well, let's learn from ohters. :(


// Solution 1 : dfs
void dfs(string& s, int index, int lefts, int rights, int pairs, string path, unordered_set<string>& result) {
    if (index == s.size()) {
        if (lefts == 0 && rights == 0 && pairs == 0) result.insert(path); // a valid path must with 0 lefts, 0 rights, and all pairs eliminated
        return;
    }
    if (s[index] == '(') {
        if (lefts > 0) dfs(s, index+1, lefts-1, rights, pairs, path, result); // remove this '('
        dfs(s, index+1, lefts, rights, pairs+1, path+s[index], result); // keep this '(', so generate a new pair
    }
    else if (s[index] == ')') {
        if (rights > 0) dfs(s, index+1, lefts, rights-1, pairs, path, result); // remove this ')'
        if (pairs > 0) dfs(s, index+1, lefts, rights, pairs-1, path+s[index], result); // keep this ')', so eliminate a pair
    }
    else // other letters
        dfs(s, index+1, lefts, rights, pairs, path+s[index], result);
}

vector<string> removeInvalidParentheses(string s) {
    unordered_set<string> result;
    int lefts = 0, rights = 0; // count the remained '(' and ')' that need to be removed
    for (auto & c : s) {
        if (c == '(') ++lefts;
        else if (c == ')') {
            if (lefts > 0) --lefts;
            else ++rights;
        }
    }
    // one of lefts and rights must be 0, so it is the minimum number of parentheses to be removed
    dfs(s, 0, lefts, rights, 0, "", result);
    return vector<string>(result.begin(), result.end());
}


// Solution 2 : bfs, it is close to brute-force to some extent.
// https://leetcode.com/discuss/67842/share-my-java-bfs-solution
// we do not implement it here du to its bad performance


int main() {
    auto r = removeInvalidParentheses("(a)())()");
    for (auto i:r) cout << i << endl;
    return 0;
}
