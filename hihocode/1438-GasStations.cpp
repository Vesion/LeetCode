#include <iostream>
#include <iomanip> 
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

struct Node {
    double origin, cur;
    int count;
    bool operator<(const Node& rhs) const { return cur < rhs.cur; }
};

double solve() {
    int N, M, k; 
    cin >> N >> M >> k;
    vector<int> station(N);
    for (int i = 0; i < N; ++i) cin >> station[i];

    priority_queue<Node> pq;
    for (int i = 1; i < N; ++i) {
        pq.push({(double)station[i]-station[i-1], (double)station[i]-station[i-1], 1});
    }

    while (k--) {
        Node t = pq.top(); pq.pop();
        ++t.count;
        t.cur = t.origin / t.count;
        pq.push(t);
    }
    return pq.top().cur;
}

int main() {
    cout << fixed << setprecision(1) << solve() << endl;
    return 0;
}

