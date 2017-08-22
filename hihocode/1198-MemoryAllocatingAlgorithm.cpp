#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque> 
#include <string>
using namespace std;

struct Block {
    int value, start, end;
};


int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    deque<Block> q;
    int c;
    bool written = true;
    for (int k = 1; k <= n; ++k) {
        if (written) cin >> c;
        if (q.empty())
            q.push_back({k, 0, c-1});
        else {
            bool found = false;
            int minK = n+1;
            int id = -1;
            for (int i = 0; i < (int)q.size(); ++i) {
                if (q[i].value < minK) {
                    minK = q[i].value;
                    id = i;
                }
                if (i == 0 && c-1 < q[i].start) {
                    q.push_front({k, 0, c-1});
                    found = true;
                    break;
                }
                if (i == (int)q.size()-1 && q[i].end+c < m) {
                    q.push_back({k, q[i].end+1, q[i].end+c});
                    found = true;
                    break;
                }
                if (q[i+1].start-q[i].end-1 >= c) {
                    q.insert(q.begin()+i+1, {k, q[i].end+1, q[i].end+c});
                    found = true;
                    break;
                }
            }
            if (!found) {
                q.erase(q.begin()+id);
                k--;
                written = false;
            } else 
                written = true;
        }
    }

    // for output
    sort(q.begin(), q.end(), [](const Block& b1, const Block& b2) {
        return b1.value < b2.value;
    });
    for (auto& b : q)
        cout << b.value << " " << b.start << endl;
    
    return 0;
}
