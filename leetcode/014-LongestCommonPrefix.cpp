#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        int i = 0;
        while (true) {
            char c = 0;
            for (const string& s : strs) {
                if (i >= s.size()) return res;
                if (!c) c = s[i];
                else if (s[i] != c) return res;
            }
            if (!c) return res;
            res += c;
            ++i;
        }
        return res;
    }
};

int main() {
	return 0;
}
