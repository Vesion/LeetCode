#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque> 
using namespace std;

class MovingAverage {
private:
    deque<int> q;
    int s, sum = 0;
public:
    MovingAverage(int size) {
        s = size;
    }
    
    double next(int val) {
        sum += val;
        q.push_back(val);
        if ((int)q.size() > s) {
            sum -= q.front();
            q.pop_front();
        }
        return sum*1.0 / q.size();
    }
};


int main() {
    return 0;
}
