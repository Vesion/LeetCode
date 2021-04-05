#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_set>
using namespace std;

// Problem: Pick N cards from a deck of cards (point starts from 1 to 13),
//          find the numebr of ways to manipulate the 4 integers so that the end result is 24.
//          e.g. 4, 7, 8, 8, a possible solution is (7-(8/8))*4 = 24

const int MAX = 10;
const double FMIN = 1e-6;
const int TARGET = 24;
double nums[MAX];
string e[MAX]; // print evaluating expression
int N;
int res;

void dfs(int n) {
    if (n == 1) {
        if (fabs(nums[0]-TARGET) < FMIN) {
            cout << e[0] << endl;
            ++res;
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            double a = nums[i], b = nums[j];
            string ea = e[i], eb = e[j];
            nums[j] = nums[n-1];
            e[j] = e[n-1];

            nums[i] = a+b; e[i] = "("+ea+"+"+eb+")";
            dfs(n-1);
            nums[i] = a-b; e[i] = "("+ea+"-"+eb+")";
            dfs(n-1);
            nums[i] = b-a; e[i] = "("+eb+"-"+ea+")";
            dfs(n-1);
            nums[i] = a*b; e[i] = "("+ea+"*"+eb+")";
            dfs(n-1);
            if (b) nums[i] = a/b; e[i] = "("+ea+"/"+eb+")";
            dfs(n-1);
            if (a) nums[i] = b/a; e[i] = "("+eb+"/"+ea+")";
            dfs(n-1);

            // backtracking, recover
            nums[i] = a, nums[j] = b;
            e[i] = ea, e[j] = eb;
        }
    }
}


int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        e[i] = to_string((int)nums[i]);
    }
    res = 0;
    dfs(N);
    cout << res << endl;
    return 0;
}
