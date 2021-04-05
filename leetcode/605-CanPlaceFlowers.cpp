#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        int m = flowerbed.size();
        for (int i = 0; i < m; ++i) {
            if (flowerbed[i]) continue;
            if ((i > 0 && flowerbed[i-1]) ||
                (i < m-1 && flowerbed[i+1])) continue;
            flowerbed[i] = 1;
            if (--n == 0) return true;
        }
        return false;
    }
};


int main() {
    return 0;
}
