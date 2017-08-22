#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

// Solution 1
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        while (i >= 0 && s[i] == ' ') --i;
        int j = i;
        while (j >= 0 && isalpha(s[j])) --j;
        return i-j;
    }
};


// Solution 2
class Solution_2 {
public:
    int lengthOfLastWord(string s) {
        istringstream in(s);
        string w;
        while (in >> w) ;
        return w.size();
    }
};


int main() {
    return 0;
}
