#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Binary serach + greedy heap
class Solution0 {
public:

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int lower = 0, upper = n;
        while (lower < upper) {
            int mid = lower + (upper-lower)/2;
            if (can(heights, mid, bricks, ladders)) lower = mid+1;
            else upper = mid;
        }
        return upper-1;
    }

    // greedy, use k ladders for k largest jumps
    bool can(const vector<int>& heights, int t, int bricks, int ladders) {
        if (t == 0) return true;
        priority_queue<int> pq;
        for (int i = 1; i <= t; ++i) {
            int diff = heights[i] - heights[i-1];
            if (diff > 0) pq.push(diff);
        }
        while (!pq.empty()) {
            int s = pq.top(); pq.pop();
            if (ladders) --ladders;
            else if (bricks >= s) bricks -= s;
            else return false;
        }
        return true;
    }
};

// Actually we do not need the binary search
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size();
        for (int i = 1; i < n; ++i) {
            int diff = heights[i] - heights[i-1];
            if (diff > 0) {
                pq.push(diff);
                if (pq.size() > ladders) {
                    int s = pq.top(); pq.pop();
                    if (s > bricks) return i-1;
                    bricks -= s;
                }
            }
        }
        return n-1;
    }
};

int main() {

}
