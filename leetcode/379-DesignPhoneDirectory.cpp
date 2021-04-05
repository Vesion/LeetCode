#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <numeric>
using namespace std;


// Set, O(logN)
class PhoneDirectory1 {
public:
    set<int> m;
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) m.insert(i);
    }
    int get() {
        if (m.empty()) return -1;
        int i = *m.begin();
        m.erase(i);
        return i;
    }
    bool check(int number) {
        return m.count(number);
    }
    void release(int number) {
        m.insert(number);
    }
};


// Next pointer, O(1)
class PhoneDirectory {
private:
    vector<int> next;
    int pos;

public:
    PhoneDirectory(int maxNumbers) {
        next.resize(maxNumbers);
        for (int i = 0; i < maxNumbers; ++i) next[i] = (i+1) % maxNumbers;
        pos = 0;
    }

    int get() {
        if (next[pos] == -1) return -1;
        int res = pos;
        pos = next[pos];
        next[res] = -1;
        return res;
    }

    bool check(int number) {
        return next[number] != -1;
    }

    void release(int number) {
        if (check(number)) return;
        next[number] = pos;
        pos = number;
    }
};


int main() {
    PhoneDirectory p(1);
    cout << p.check(0) <<endl;
    cout << p.get() <<endl;
    cout << p.check(0) <<endl;
    cout << p.get() <<endl;
    p.release(0);
    cout << p.check(0) <<endl;
    cout << p.get() <<endl;
    cout << p.check(0) <<endl;
    cout << p.get() <<endl;
    return 0;
}
