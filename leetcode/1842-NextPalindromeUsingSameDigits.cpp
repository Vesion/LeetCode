#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// similar to 556.NextGreaterElementIII
class Solution {
public:
    string nextPalindrome(string num) {
        int n = num.size();
        string s = num.substr(0, n/2);
        if (next_permutation(s.begin(), s.end())) {
            string rs = s;
            reverse(rs.begin(), rs.end());
            if (n%2) return s + num[n/2] + rs;
            else return s + rs;
        }
        return "";
    }

};


int main() {

}
