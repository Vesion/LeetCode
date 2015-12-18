#include <iostream>
#include <vector>
#include <memory.h>
#include <inttypes.h>
#include <stdio.h>
using namespace std;

// bit-map, O(n)
int firstMissingPositive(vector<int>& nums) {
    if (nums.size() == 0)
        return 1;
    const int LIMIT = 80000; // due to Leetcode stack memory limit
    uint8_t map[LIMIT] = {0};
    memset(map, 0, LIMIT);
    int result = 0;
    for (auto i : nums) {
        if (i > 0) {
            int index = (i - 1) / 8;
            uint8_t m = map[index];
            m |= ((0x1) << ((i-1) % 8));
            //printf("%u\n", m);
            map[index] = m;
        }
    }
    for (int i = 0; i < LIMIT; ++i) {
        //printf("%u\n", map[i]);
        if (map[i] ^ 0xff) {
            int offset = 1;
            while (map[i] & 0x01) {
                ++offset;
                map[i] >>= 1;
            }
            result = i * 8 + offset;
            break;
        }
    }
    return result;
}

/* Another solution is bucket-sort, whose idea is similar with above.
 * I don't implement here beacause it will not have a better performance.
 */ 

int main() {
    //vector<int> a{10, 9, 8, 7, 1, 2, 4, 3, 5, 6};
    vector<int> a{};
    cout << firstMissingPositive(a);
    return 0;
}
