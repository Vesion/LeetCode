#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 50082;
int s[MAX];
int n, num;
int res;

void combine(int k) {
    // merge
    int tmp = s[k-1] + s[k];
    res += tmp;
    // move s[k+1...] to s[k...]
    for (int i = k; i < num-1; ++i) s[i] = s[i+1];
    num--;
    // insert
    int j;
    for (j = k-1; j > 0 && s[j-1] < tmp; --j) s[j] = s[j-1];
    s[j] = tmp;
    // backtracking
    while (j >= 2 && s[j] >= s[j-2]) {
        int d = num - j;
        combine(j-1);
        j = num - d;
    }
}

int main() {
    while (cin >> n && n > 0) {
        for (int i = 0; i < n; ++i) scanf("%d", &s[i]);
        num = 1;
        res = 0;
        for (int i = 1; i < n; ++i) {
            s[num++] = s[i];
            while (num >= 3 && s[num-3] <= s[num-1]) combine(num-2);
        }
        while (num > 1) combine(num-1);
        cout << res << endl;
    }
    return 0;
}
