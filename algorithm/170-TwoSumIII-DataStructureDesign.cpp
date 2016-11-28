#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

class TwoSum {
private:
    unordered_multiset<int> s;

public:

    // O(1)
	void add(int number) {
        s.insert(number);
	}

    // O(n)
	bool find(int value) {
        for (int num : s) {
            int c = num == (value-num) ? 1 : 0;
            if ((int)s.count(value-num) > c) return true;
        }
        return false;
	}
};

int main() {
    TwoSum t;
    t.add(1);
    t.add(2);
    cout << t.find(3) << endl;
    return 0;
}
