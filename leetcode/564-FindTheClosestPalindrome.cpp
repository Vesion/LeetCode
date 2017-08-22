#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string num) {
        int n = num.size();
        if (n == 0 || num == "0") return "0";
        if (n == 1) { num[0] -= 1; return num; }

        string prefix = num.substr(0, (n+1)/2);
        string res(n+1, '0'); res[0] = res[n] = '1';
        string mindiff = absSub(res, num);
        for (string& b : vector<string>{"-1", "0", "1"}) {
            string r = add(prefix, b);
            string t = r.substr(0, n/2); reverse(t.begin(), t.end());
            r += t;
            if (r == num) continue;
            string diff = absSub(r, num);
            if (bigger(mindiff, diff) || (mindiff == diff && bigger(res, r))) mindiff = diff, res = r;
        }
        string r = string(n-1, '9');
        string diff = absSub(r, num);
        if (bigger(mindiff, diff) || (mindiff == diff && bigger(res, r))) mindiff = diff, res = r;
        return res;
    }

    bool bigger(const string& a, const string& b) {
        return a.size() == b.size() ? a > b : a.size() > b.size();
    }

    string absSub(const string& a, const string& b) {
        if (bigger(b, a)) return absSub(b, a);
        string res;
        for (int i = a.size()-1, j = b.size()-1, carry = 0; i >= 0 || j >= 0; ) {
            int na = a[i--]-'0'-carry;
            int nb = j >= 0 ? b[j--]-'0' : 0;
            if (na < nb) na += 10, carry = 1;
            else carry = 0;
            res += to_string(na-nb);
        }
        reverse(res.begin(), res.end());
        auto it = res.find_first_not_of('0');
        return it == string::npos ? "0" : res.substr(it);
    }

    string add(const string& a, const string& b) {
        if (b[0] == '-') return absSub(a, b.substr(1));
        string res;
        for (int i = a.size()-1, j = b.size()-1, carry = 0; i >= 0 || j >= 0 || carry; carry /= 10) {
            if (i >= 0) carry += a[i--]-'0';
            if (j >= 0) carry += b[j--]-'0';
            res += to_string(carry%10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {
    Solution s;
    cout << s.nearestPalindromic("55") << endl;
    return 0;
}
