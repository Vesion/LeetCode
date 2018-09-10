#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// KMP, O(n)
// return the times t occurring in s

int kmp(string s, string t) {
    int n = s.size(), m = t.size();

    // calculate prefix array
    vector<int> prefix(m, 0);
    int j = 0;
    for (int i = 1; i < (int)t.size(); ++i) {
        while (j > 0 && t[j] != t[i]) j = prefix[j-1];
        if (t[i] == t[j]) ++j;
        prefix[i] = j;
    }

    j = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && s[i] != t[j]) j = prefix[j-1];
        if (s[i] == t[j]) ++j;
        if (j == m) {
            ++count;
            // the position is i-j+1
        }
    }
    return count;
}


// Application of KMP (or prefix array):
// 1. Judge self-repeated string:
//      Given a string s of length n, calculate the prefix array of s, if prefix[n-1] > 0 && n % (n-prefix[n-1]) == 0,
//      then s is a self-repeated string, the repeated pattern is n-prefix[n-1]
//          e.g. s = "12121212", prefix[n-1] = 6, the repeated pattern is "12"
// 
// 2. Get the longest prefix palindrome substring
//      Given a string s, what is the longest prefix palidrome substring of it?
//      Reverse s and append it to s as a new string t, calculate the prefix array of t
//      then the longest prefix palindrome substring is s[0, prefix[t.size()-1])


int main() {
    cout << kmp("123456456789", "123412341212");    
    return 0;
}
