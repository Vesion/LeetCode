#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;


// Similar to 205-IsomorphicStrings
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream in(str);
        string w; 
        for (int i = 0; i < pattern.size(); ++i) {
            if (in.eof()) return false;
            in >> w;
            char c = pattern[i];
            if (m1[c] != m2[w]) return false;
            m1[c] = m2[w] = i+1;
        }
        if (!in.eof()) return false;
        return true;
    }
};

int main() {
    return 0;
}
