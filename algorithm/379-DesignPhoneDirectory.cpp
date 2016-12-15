#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list> 
#include <unordered_map> 
using namespace std;

// Although 'List' is in problem tag, but list solution gets TLE!
// So, we use array indexing to simulate list.

class PhoneDirectory {
private:
    vector<int> pool;
    vector<bool> used;
    int index, upper;

public:
    PhoneDirectory(int maxNumbers) : pool(maxNumbers), used(maxNumbers, false), index(0), upper(maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) pool[i] = i;
    }

    int get() {
        if (index >= upper) return -1;
        int res = pool[index++];
        used[res] = true;
        return res;
    }

    bool check(int number) {
        if (number < 0 || number >= upper) return false;
        return !used[number];
    }

    void release(int number) {
        if (number < 0 || number >= upper || !used[number]) return;
        pool[--index] = number;
        used[number] = false;
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
