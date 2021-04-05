#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    struct Car {
        int pos, speed;
    };
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        int n = position.size();
        cars.reserve(n);
        for (int i = 0; i < n; ++i) cars.push_back({position[i], speed[i]});
        sort(cars.begin(), cars.end(),
            [](const Car& c1, const Car& c2) { return c1.pos > c2.pos; });
        float last_t = -1, fleet = 0;
        for (int i = 0; i < n; ++i) {
            float t = (target - cars[i].pos) / static_cast<float>(cars[i].speed);
            if (t > last_t) {
                ++fleet;
                last_t = t;
            }
        }
        return fleet;
    }
};

int main() {

}