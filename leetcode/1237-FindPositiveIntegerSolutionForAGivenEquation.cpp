#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


// Binary search
class Solution {
public:
    const int kMax = 1001;
    vector<vector<int>> findSolution(CustomFunction& func, int z) {
        vector<vector<int>> res;
        for (int x = 1; x < kMax; ++x) {
            int ly = 1, ry = kMax;
            while (ly < ry) {
                int mid = ly + (ry-ly)/2;
                int t = func.f(x, mid);
                if (t == z) {
                    res.push_back({x, mid});
                    break;
                }
                else if (t < z) ly = mid+1;
                else ry = mid;
            }
        }
        return res;
    }
};

int main() {

}