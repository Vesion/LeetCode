#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        string res = "1";
        while (--n) {
            string tmp;
            int i = 0;
            while (i < (int)res.size()) {
                int j = i+1;
                while (j < (int)res.size() && res[j] == res[i]) ++j;
                tmp += to_string(j-i) + res[i];
                i = j;
            }
            res = tmp;
        }
        return res;
        
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(3);
    return 0;
}

