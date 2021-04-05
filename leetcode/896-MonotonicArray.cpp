#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool inc = false, dec = false;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] == A[i-1]) continue;
            if (A[i] > A[i-1]) {
                if (dec) return false;
                inc = true;
                dec = false;
            } else {
                if (inc) return false;
                dec = true;
                inc = false;
            }
        }
        return true;
    }
};

int main() {
}