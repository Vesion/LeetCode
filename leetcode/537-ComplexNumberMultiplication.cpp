#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int r1 = 0, i1 = 0, r2 = 0, i2 = 0;
        getRI(a, r1, i1);
        getRI(b, r2, i2);
        int r = r1*r2 - i1*i2;
        int i = r1*i2 + r2*i1;
        return to_string(r) + "+" + to_string(i) + "i";
    }
    
    void getRI(string& a, int& r, int& i) {
        int num = 0, sign = 1;
        for (int j = 0; j < (int)a.size()-1; ++j) {
            if (a[j] == '-') sign = -1;
            else if (a[j] == '+') {
                r = num*sign;
                num = 0, sign = 1;
            } else num = num*10 + a[j]-'0';
        }
        i = num*sign;
    }
};


int main() {
    return 0;
}
