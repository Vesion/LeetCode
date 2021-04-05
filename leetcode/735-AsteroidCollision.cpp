#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// stack
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int i = 0; i < asteroids.size(); ++i) {
            int a = asteroids[i];
            if (res.empty() || a > 0 || res.back() < 0) res.push_back(a);
            else if (-a >= res.back()) {
                if (-a > res.back()) --i;
                res.pop_back();
            }
        }
        return res;
    }
};

int main() {
  return 0;
}
