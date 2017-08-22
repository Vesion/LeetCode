#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <fstream>
using namespace std;

typedef long long ll;

inline ll getsp(vector<int>& ps, int k) {
    priority_queue<int> buffer;
    for (int i = 0; i < k; ++i) buffer.push(ps[i]);
    ll sum = 0;
    int cnt = 1;
    for (int i = k; i < ps.size(); ++i) {
        sum += (buffer.top() * (cnt++));
        buffer.pop();
        buffer.push(ps[i]);
    }
    while (!buffer.empty()) {
        sum += (buffer.top() * (cnt++));
        buffer.pop();
    }
    return sum;
}

int main() {
    //ifstream cin("in.txt");
    int N;
    ll Q;
    cin >> N >> Q;
    vector<int> ps(N);
    for (int i = 0; i < N; ++i)
        cin >> ps[i];
    
    // use binary search, rather than sequentially scan
    int left = 1, right = N, result = -1;
    while (left <= right) {
        int mid = (left+right) >> 1;
        if (getsp(ps, mid) <= Q) { // if find one, record it, and continue to narrow bound
            right = mid-1;
            result = mid;
        } else
            left = mid+1;
    }
    cout << result << endl;

    return 0;
}
