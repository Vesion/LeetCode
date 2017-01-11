#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;

// use log2(num) to get the MSB
class Solution {
public:
    int findComplement(int num) {
        return ~num & ((1 << (int)log2(num)) - 1);
    }
};


int main() {
    return 0;
}
