#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// Queue
class ZigzagIterator {
    using vit = vector<int>::iterator;
    queue<pair<vit, vit>> q;
    
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) q.push({v1.begin(), v1.end()});
        if (!v2.empty()) q.push({v2.begin(), v2.end()});
    }

    int next() {
        auto t = q.front();
        q.pop();
        int res = *t.first++;
        if (t.first != t.second) q.push(t);
        return res;
    }

    bool hasNext() {
        return !q.empty();
    }
};

int main() {
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {6,7,8};
    ZigzagIterator z(v1, v2);
    while (z.hasNext()) cout << z.next() << endl;
    return 0;
}

