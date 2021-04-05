#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// similar to 295-FindMedianFromDataStream
// use three multisets:
// left, to store smallest k numbers
// right, to store largest k numbers
// mid, to store remaining (m-2*k) numbers
class MKAverage {
    using ll = long long;
    multiset<int> left, mid, right;
    int m, k, n;
    ll sum;
    deque<int> q;

    void add(int num) {
        left.insert(num);
        if (left.size() > k) {
            auto it = prev(left.end());
            mid.insert(*it);
            sum += *it;
            left.erase(it);
        }
        if (mid.size() > n) {
            auto it = prev(mid.end());
            right.insert(*it);
            sum -= *it;
            mid.erase(it);
        }
    }

    void remove(int num) {
        // NOTE: do not use left.erase(num) because it will erase all elements equal to num,
        //       here we want to erase only one.
        if (num <= *left.rbegin()) {
            left.erase(left.find(num));
        } else if (num <= *mid.rbegin()) {
            mid.erase(mid.find(num));
            sum -= num;
        } else {
            right.erase(right.find(num));
        }

        if (left.size() < k) {
            auto it = mid.begin();
            left.insert(*it);
            sum -= *it;
            mid.erase(it);
        }
        if (mid.size() < n) {
            auto it = right.begin();
            mid.insert(*it);
            sum += *it;
            right.erase(it);
        }
    }

public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
        n = m-2*k;
        sum = 0;
    }

    void addElement(int num) {
        if (q.size() >= m) {
            remove(q.front());
            q.pop_front();
        }
        add(num);
        q.push_back(num);
    }

    int calculateMKAverage() {
        if (q.size() < m) return -1;
        return sum / n;
    }
};

int main() {

}