#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

class SnapshotArray {
public:
    vector<vector<pair<int,int>>> snaps;
    int snapid = 0;

    SnapshotArray(int length) {
        snaps.resize(length);
        for (int i = 0; i < length; ++i) snaps[i].push_back({0, 0});
    }

    void set(int index, int val) {
        auto& h = snaps[index];
        if (h.back().first < snapid) h.push_back({snapid, val});
        else h.back().second = val;
    }

    int snap() {
        return snapid++;
    }

    int get(int index, int snap_id) {
        assert(snap_id <= snapid);
        const auto& h = snaps[index];
        auto it = upper_bound(h.begin(), h.end(), snap_id,
            [](int id, const pair<int,int>& p) {
                return id < p.first;
            });
        return prev(it)->second;
    }
};

int main() {
    SnapshotArray s(1);
    s.set(0,1);s.set(0,2);
    s.snap();s.snap();
    cout << s.get(0,0) << endl; cout << s.get(0,0) << endl;
    s.snap();
}















