#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

/*
 * greedy algorithms
 * Using a map store each char's index.
 * So, we can be easy to know the when duplication and the previous duplicated char's index.
 * Then we can take out the previous duplicated char, and keep tracking the maxiumn length. 
 */

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (n <= 1) return n;
    int result = 0;
    int start = 0; // store the last repeated character's position
    vector<int> table(256, -1); // use vector rather than unordered_map, much faster
    for (int i = 0; i < n; ++i) {
        if (table[s[i]] >= start) // if this char has occurred and its last occurred position is after start
            start = table[s[i]] + 1; // refresh start
        result = max(result, i-start+1); // maitain result with greedy
        table[s[i]] = i; // store every char's newest position
    }
    return result;
}

int main() {
    string s1 = "abba";
    cout<<lengthOfLongestSubstring(s1)<<endl;
    return 0;
}
