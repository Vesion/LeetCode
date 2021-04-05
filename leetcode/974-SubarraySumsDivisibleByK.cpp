#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar to 523-ContinuousSubarraySum
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int,int> m;
        m[0] = 1;
        int sum = 0, res = 0;
        for (int a : A) {
            // a can be negative, so use a%K+K
            sum = (sum + a%K + K) % K;
            auto it = m.find(sum);
            res += m[sum]++;
        }
        return res;
    }
};

int main() {

}