#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream in(s);
        string w, res;
        while (in >> w) {
            reverse(w.begin(), w.end());
            res += w + " ";
        }
        res.pop_back();
        return res;
    }
};

int main() {
    return 0;
}
