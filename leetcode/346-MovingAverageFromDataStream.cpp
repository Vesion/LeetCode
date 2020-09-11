#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;

class MovingAverage {
public:
    int capacity = 0;
    int sum = 0;
    deque<int> nums;

    MovingAverage(int size) {
        capacity = size;
        sum = 0;
        nums.clear();
    }

    double next(int val) {
        if (capacity <= 0) {
            return 0.0;
        }
        nums.push_back(val);
        sum += val;
        if (nums.size() > capacity) {
            sum -= nums.front();
            nums.pop_front();
        }
        return sum * 1.0 / nums.size();
    }
};


int main() {
    return 0;
}
