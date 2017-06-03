#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int i = m, j = n;
        for (auto& p : ops) {
            i = min(i, p[0]);
            j = min(j, p[1]);
        }
        return i*j;
    }
};


int main() {
    return 0;
}
