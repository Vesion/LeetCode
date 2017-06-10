#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m =flowerbed.size();
        for (int i = 0; i < m; ++i) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == m-1 || flowerbed[i+1] == 0)) {
                --n;
                flowerbed[i] = 1;
            }
        }
        return n <= 0;
    }
};


int main() {
    return 0;
}
