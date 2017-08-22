#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;
using ll = long long;

const int MAXN = 105;
int a[MAXN];
int N;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];
    int left = 0, right = 0;
    for (int i = 0; i < N/2; ++i) left += a[i];
    for (int i = N/2; i < N; ++i) right += a[i];
    cout << abs(left-right) << endl;
    return 0;
}
