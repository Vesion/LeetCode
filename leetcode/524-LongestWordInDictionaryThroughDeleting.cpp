#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;
        for (string& t : d) {
            if (isSubsequence(s, t) && (t.size() > res.size() || (t.size() == res.size() && t < res))) res = t;
        }
        return res;
    }
    
    bool isSubsequence(string& s, string t) {
        int i = 0;
        for (char& c : s) if (c == t[i]) ++i;
        return i == (int)t.size();
    }
};


int main() {
    return 0;
}
