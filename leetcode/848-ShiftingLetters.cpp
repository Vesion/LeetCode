#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        string res = s;
        int sum = 0;
        for (int i = shifts.size()-1; i >= 0; --i) {
            sum = (sum + shifts[i]) % 26;
            res[i] = ((res[i]-'a') + sum)%26 + 'a';
        }
        return res;
    }
};

int main() {
}
