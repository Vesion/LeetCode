#include <iostream>
#include <queue>
#include <vector>
using namespace std;


// The key idea is to use two heaps, one max-heap(small) to store smaller half part, and one min-heap(large) to store larger half part.
// Then the top of small is the largest one of smaller half part, the top if large is the smallest one of larger half part.
// To deal with odd and even, we promise the size of small is 1 larger than large, or equal to large.

class MedianFinder {
private:
    priority_queue<int> small; // max-heap, store the smaller half part
    priority_queue<int, vector<int>, greater<int>> large; // min-heap, store the larger half part

public:
    void addNum(int num) {
        if (small.empty() || num <= small.top()) small.push(num);
        else large.push(num);

        if (large.size() == small.size()+1) {
            small.push(large.top());
            large.pop();
        } else if (small.size() == large.size()+2) {
            large.push(small.top());
            small.pop();
        }
    }

    double findMedian() {
        if (small.empty()) return 0;
        if (small.size() > large.size()) return small.top();
        return (small.top() + large.top()) * 0.5;
    }
};

int main() {
    MedianFinder f;
    f.addNum(1);
    f.addNum(2);
    f.addNum(3);
    f.addNum(4);
    cout << f.findMedian() << endl;

    return 0;
}

