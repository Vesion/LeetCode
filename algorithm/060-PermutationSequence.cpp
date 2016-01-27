#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// brute-force, TLE!!
string getPermutation_tle(int n, int k) {
    string s(n, '1');
    for (int i = 0; i < n; ++i)
        s[i] += i;
    while (k-- != 1)
        next_permutation(s.begin(), s.end());
    return s;
}

// 康拓展开，中介数
string getPermutation(int n, int k) {
    vector<int> pow(n, 1);
    for (int i = 1; i < n; ++i)
        pow[i] = pow[i-1] * i;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i)
        nums[i] = i + 1;
    string result;

    k--;
    for (int i = 0; i < n; ++i) {
        int num = k / pow[n-i-1];
        k %= pow[n-i-1];
        result += (*(nums.begin() + num) + '0');
        nums.erase(nums.begin() + num);
    }
    return result;
}


int main() {
    cout << getPermutation(8, 8590);
    cout << getPermutation_tle(8, 8590);
    return 0;
}
