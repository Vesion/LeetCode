#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
using namespace std;

class HitCounter {
private:
    vector<int> times, hits;

public:
    HitCounter() {
        times.resize(300, 0);
        hits.resize(300, 0);
    }
    
    void hit(int timestamp) {
        int i = timestamp % 300;
        if (times[i] != timestamp) {
            times[i] = timestamp;
            hits[i] = 1;
        } else
            hits[i]++;
    }
    
    int getHits(int timestamp) {
        int res = 0;
        for (int i = 0; i < 300; ++i) {
            if (timestamp-times[i] < 300)
                res += hits[i];
        }
        return res;
    }
};


int main() {
    HitCounter h;
    h.hit(1);
    h.hit(1);
    h.hit(1);
    h.hit(300);
    //cout << h.getHits(300) << endl;;
    h.hit(300);
    //cout << h.getHits(300) << endl;;
    h.hit(301);
    cout << h.getHits(301) << endl;;
    return 0;
}
