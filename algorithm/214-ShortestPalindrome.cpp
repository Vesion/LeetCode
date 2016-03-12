#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Solution 0 : trivial, find longest palindromic prefix substring, O(n^2) time, TLE!
// e.g. if s is "abacbbcda", so the longest palindromic prefix substring is "aba", we reverse the rs substring and get "adcbbc", so the result is "adcbbc" + "abacbbcda"
bool isPalindrome(string &s, int left, int right) {
    while (left <= right && s[left] == s[right]) ++left, --right;
    return left >= right;
}

string shortestPalindrome_n2_tle(string s) {
    int n = s.size();
    if (n < 2) return s;
    int right = n-1;
    while (right >= 0) {
        if (isPalindrome(s, 0, right)) break;
        --right;
    }
    string rs = s.substr(right+1);
    reverse(rs.begin(), rs.end());
    return rs + s;
}


// Solution 1 : or Solution 0 improvement. O(n^2) time
// improve the finding longest palindromic prefix substring process, much faster
string shortestPalindrome_n2(string s) {
    int n = s.length();
    if (n < 2) return s;
    int longest = 1, start, end;
    for (int i = 0; i <= n / 2;) {
        start = end = i;
        // why is v2 much faster than the trivial O(n^2) solution, here is the key improvement
        // this while loop skip all repetitive chars, so it is much faster in such case "aaaaa..."
        while (end < n - 1 && s[end + 1] == s[end])
            ++end;
        i = end + 1;
        while (end < n - 1 && start > 0 && s[end + 1] == s[start - 1]) {
            ++end;
            --start;
        }
        if (start == 0) longest = max(longest, end+1);
    }
    string rs = s.substr(longest);
    reverse(rs.begin(), rs.end());
    return rs + s;
}


// Solution 2 : use the 'prefix array' in KMP algorithm, O(n) time
//      Step 1: we construct a new string t with (s) + '#' + (reversed s)
//      Step 2: calculate the prefix array of t
//      Step 3: watch the last value, it shows us the largest suffix of the reversed string that matches the prefix of the original string.
//      Step 4: add the first k characters of the reversed string to the original string, where k is a difference between original string size and the prefix function for the last character of a constructed string.
//      e.g. s is "abacdef", so t is "abacdef#fedcaba", the last value of prefux array is 3, so the result is "fedcabacdef"
string shortestPalindrome_kmp(string s) {
    int n = s.size();
    if (n < 2) return s;
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    string t = s + "#" + rev_s;
    int l = t.size();
    vector<int> prefix(l, 0);
    for (int i = 1; i < l; i++) {
        int j = prefix[i-1];
        while (j > 0 && t[i] != t[j])
            j = prefix[j-1];
        prefix[i] = (j += t[i] == t[j]);
    }
    return rev_s.substr(0, n - prefix[l-1]) + s;
}

int main() {
    cout << shortestPalindrome_n2_tle("abcbbbb") << endl;
    cout << shortestPalindrome_n2("abcbbbb") << endl;
    cout << shortestPalindrome_kmp("abcbbbb") << endl;
    return 0;
}
