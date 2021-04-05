#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        string res;
        int i = 0;
        for (char c : number) {
            if (c == '-' || c == ' ') continue;
            res += c;
            if (++i == 3) {
                res += '-';
                i = 0;
            }
        }
        if (res.back() == '-') res.pop_back();
        int n = res.size();
        if (i == 1) swap(res[n-2], res[n-3]);
        return res;
    }
};

int main() {
}
