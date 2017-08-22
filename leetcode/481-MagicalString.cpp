#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int i = 2;
        while ((int)s.size() < n) {
            int num = s[i++] - '0';
            s += string(num, s.back() == '1' ? '2' : '1');
        }
        return count(s.begin(), s.begin()+n, '1');
    }
};


int main() {
    return 0;
}
