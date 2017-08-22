#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < (int)s.size(); i += 2*k) reverse(s.begin()+i, min(s.begin()+i+k, s.end()));
        return s;
    }
};


int main() {
    return 0;
}
