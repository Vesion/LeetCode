#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Solution 1: brute-force traversal, O(n^2)
// traverse the whole string, start finding the palindrome from each char (extend to left and right), get the longest substr
string findPalindrome(string s, int l, int r) {
	int n = s.size();
	while (l >= 0 && r < n && s[l] == s[r]) {
		--l;
		++r;
	}
	return s.substr(l + 1, r - l - 1);
}

string longestPalindrome_n2(string s) {
	if (s.size() <= 1)
		return s;
	string longest, str;
	for (int i = 0; i < s.size() - 1; i++) {
		str = findPalindrome(s, i, i);
		if (str.size() > longest.size())
			longest = str;

		str = findPalindrome(s, i, i + 1);
		if (str.size() > longest.size())
			longest = str;
	}
	return longest;
}


// Solution 2 : Manacher's Algorithm, O(n)
// http://www.felix021.com/blog/read.php?2040
string preProcess(string& s) {
    string t = "$#";
    for (int i = 0; i < s.size(); ++i) t += s.substr(i, 1) + "#";
    return t;
}
string longestPalindrome_n(string s) {
    if (s.size() < 2) return s;
    string t = preProcess(s);
    int n = t.size();
    vector<int> p(n, 0);
    int mx = 0, id = 0;
    for (int i = 1; i < n; ++i) {
        p[i] = mx > i ? min(p[2*id-i], mx-i) : 1;
        while (t[i+p[i]] == t[i-p[i]]) ++p[i];
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }
    int maxLen = 0, center = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] > maxLen) {
            maxLen = p[i];
            center = i;
        }
    }
    return s.substr(center/2 - maxLen/2, maxLen-1);
}

int main() {
    string s = "bb";
    cout << longestPalindrome_n2(s) << endl;
	cout << longestPalindrome_n(s) << endl;
	return 0;
}
