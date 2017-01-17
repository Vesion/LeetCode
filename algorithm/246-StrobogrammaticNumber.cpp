#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        if (num.empty()) return false;
        unordered_map<char, char> m = {{'0','0'}, {'1','1'}, {'6','9'}, {'8','8'}, {'9','6'}};
        int n = num.size();
        for (int i = 0; i < n/2+1; ++i) {
            if (!(m.count(num[i]) && num[n-i-1] == m[num[i]])) return false;
        }
        return true;
    }
};


int main() {
    return 0;
}
