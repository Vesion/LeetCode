#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    struct E {
        int q;
        double v;  // wage need to pay for per unit of quality
        E(int q_, int w_) : q(q_), v(w_*1.0/q_) {}
        bool operator<(const E& e) const {
            return v < e.v;
        }
    };
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        vector<E> es;
        for (int i = 0; i < n; ++i) es.emplace_back(quality[i], wage[i]);
        sort(es.begin(), es.end());

        // since e has been sorted in increasing order,
        // qsum * e.v is the minimum wages we need to pay K workers,
        // so our taget is to minium qsum
        double qsum = 0;
        double res = DBL_MAX;
        priority_queue<double> pq;
        for (const E& e : es) {
            pq.push(e.q);
            qsum += e.q;
            if (pq.size() > K) {
                qsum -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) {
                res = min(res, qsum * e.v);
            }
        }
        return res;
    }
};

int main() {

}
