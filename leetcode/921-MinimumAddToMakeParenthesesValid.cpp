#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0;
        int res = 0;
        for (char c : S) {
            if (c == '(') ++left;
            else {
                if (left == 0) ++res;
                else --left;
            }
        }
        return res + left;
    }
};

int main() {

}
