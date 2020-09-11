#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Min heap, O(nlogn)
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        const int n = hand.size();
        if (n % W != 0) return false;
        if (W == 1) return true;

        const int groups = n / W;
        sort(hand.begin(), hand.end());
        using P = pair<int,int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        int c = 0;
        for (int card : hand) {
            if (pq.empty()) {
                pq.push({card, 1});
                continue;
            }
            const P group = pq.top();  // NOTE: no &
            if (card < group.first || card > group.first + 1) return false;
            if (card == group.first) {
                pq.push({card, 1});
            } else {
                pq.pop();
                if (group.second+1 == W) ++c;
                else pq.push({card, group.second+1});
            }
        }
        return c == groups;
    }
};

// Map and count
class Solution1 {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int,int> m;
        for (int card : hand) ++m[card];
        for (const auto p : m) {  // NOTE: no &
            assert(p.second >= 0);
            if (p.second == 0) continue;
            for (int i = 0; i < W; ++i) {
                if ((m[p.first + i] -= p.second) < 0) return false;
            }
        }
        return true;
    }
};


int main() {
    return 0;
}
