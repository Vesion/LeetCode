#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

// Solution 1 : sstream
class Solution {
public:
    void reverseWords(string &s) {
        istringstream in(s);
        s.clear();
        string w;
        while (in >> w) {
            s = w + (s.empty() ? s : " " + s);
        }
    }
};


// Solution 2 : swap in-place
class Solution_2 {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] != ' ') ++j;
            reverse(s.begin()+i, s.begin()+j);
            i = j+1;
        }
    }
};


int main() {
    Solution_2 s;
    string a = "hello world you";
    s.reverseWords(a);
    cout << a << endl;
    return 0;
}
