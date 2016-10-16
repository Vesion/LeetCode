#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    //string d[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    //                 z      o       w       h        u       f       x    s          g      n
    string originalDigits(string s) {
        int m[26];
        fill_n(m, 26, 0);
        for (char& c : s) m[c-'a']++;
        string result = "";
        result += string(m['z'-'a'], '0'); // 0
        result += string(m['w'-'a'], '2'); // 2
        result += string(m['u'-'a'], '4'); // 4
        result += string(m['x'-'a'], '6'); // 6
        result += string(m['g'-'a'], '8'); // 8
        m['f'-'a'] -= m['u'-'a'];
        result += string(m['f'-'a'], '5'); // 5
        m['s'-'a'] -= m['x'-'a'];
        result += string(m['s'-'a'], '7'); // 7
        m['h'-'a'] -= m['g'-'a'];
        result += string(m['h'-'a'], '3'); // 3
        m['o'-'a'] -= (m['z'-'a'] + m['w'-'a'] + m['u'-'a']);
        result += string(m['o'-'a'], '1'); // 1
        m['n'-'a'] -= (m['o'-'a'] + m['s'-'a']);
        result += string(m['n'-'a']/2, '9'); // 9
        sort(result.begin(), result.end());
        return result;

    }
};

int main() {
    Solution s;
    cout << s.originalDigits("fviefuro");
    return 0;
}
