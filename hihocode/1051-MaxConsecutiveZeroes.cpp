#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 101;
int nums[MAX];
int n, m;

int main() {
    int T; cin >> T;
    while (T--) {
        memset(nums, 0, sizeof nums);
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            nums[a] = 1;
        }
        int i = 1, j = 1, c = 0;
        int res = 0;
        while (j < MAX) {
            if (nums[j++] == 1) ++c;
            while (c > m) {
                if (nums[i++] == 1) --c;
            }
            res = max(res, j-i);
        }
        cout << res << endl;
    }
    return 0;
}
