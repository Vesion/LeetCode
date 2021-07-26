#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class TwoSum {
    unordered_map<int,int> m;
public:
    void add(int number) {
        m[number]++;
    }

    bool find(int value) {
        for (auto it = m.begin(); it != m.end(); it++) {
            long long i = it->first;
            long long j = value - i;
            if ((i == j && it->second > 1) || (i != j && m.find(j) != m.end())) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
