#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


// distributive property of XOR and AND
// (a&b)^(a&c) = a&(b^c)
// (a[i]&b[0])^(a[i]&b[1])^...=a[i]&(b[0]^b[1]^...)
class Solution {
public:
    int getXORSum(vector<int>& a, vector<int>& b) {
        int axor = 0, bxor = 0;
        for (int num : a) axor ^= num;
        for (int num : b) bxor ^= num;
        return axor & bxor;
    }
};


int main() {

}